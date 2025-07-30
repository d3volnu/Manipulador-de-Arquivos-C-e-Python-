import os
import shutil
import mimetypes
from pathlib import Path

CATEGORIAS = {
    "image" : "Imagens",
    "video" : "Vídeos",
    "audio" : "Áudios",
    "text" : "Textos",
    "application/pdf" : "PDFs",
    "application/zip" : "Arquivos Compactados",
    "application/x-rar-compressed" : "Arquivos Compactados",
    "application/msword" : "Documentos do Word"
}

def categorizar_arquivo(mime_type):
    if mime_type is None:
        return "Outros"
    for chave in CATEGORIAS:
        if mime_type.startswith(chave):
            return CATEGORIAS[chave]
    return CATEGORIAS.get(mime_type, "Outros")

def organizar_pasta(diretorio):
    arquivos = [f for f in os.listdir(diretorio) if os.path.isfile(os.path.join(diretorio, f))]

    for arquivo in arquivos:
        if arquivo == os.path.basename(__file__):
            continue

        caminho_arquivo = os.path.join(diretorio, arquivo)
        mime_type, _ = mimetypes.guess_type(caminho_arquivo)
        categoria = categorizar_arquivo(mime_type)

        pasta_destino = os.path.join(diretorio, categoria)
        os.makedirs(pasta_destino, exist_ok=True)

        novo_caminho = os.path.join(pasta_destino, arquivo)
        shutil.move(caminho_arquivo, novo_caminho)

        print(f"Movendo {arquivo} para {categoria}")

if __name__ == "__main__":
    organizar_pasta(os.getcwd())

#SALVE PRO CHAT DO COPILOT