---
title: "Erro RW2003 (compilador de recurso) | Microsoft Docs"
ms.custom: ""
ms.date: "11/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "RW2003"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RW2003"
ms.assetid: 9dc0ba70-6776-4aef-b316-5f1711d8e42e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro RW2003 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Erro de geração  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  **Erro: O arquivo do Arquivo de bitmap não estiver no formato 3,00**  
  
     Os bitmaps que usam o formato da versão 2.x do windows não podem ser usados em arquivos de recurso de versão 3.x.  O bitmap deve ser redesenhado ou convertido no formato 3.x.  
  
2.  **Erro: DIB antiga em muitos nome.  Transfira com SDKPAINT**  
  
     Um bitmap independente \(DIB\) do dispositivo no recurso especificado não é compatível com o formato do windows 3,0.  O bitmap deve ser redesenhado ou convertido no formato 3.x.  
  
3.  **Erro: O recurso nome do arquivo de recurso não está no formato 3,00**  
  
     Um ícone ou um cursor no recurso especificado usaram um formato de uma versão anterior do windows.  O ícone ou o cursor devem ser redesenhados ou convertido no formato 3.x.  
  
4.  **Formato de cabeçalho de DIB desconhecido**  
  
     O cabeçalho de bitmap não é uma estrutura de BITMAPCOREHEADER ou de BITMAPINFOHEADER.  
  
5.  **Impossível inicializar as informações de símbolo**  
  
     Esse erro ocorre somente no Visual C\+\+.  A causa provável é que você tiver muitos arquivos abertos ou você não pode abrir ou gravar os arquivos de dados necessários para que o Visual C\+\+ importar os símbolos no script.  Visual C\+\+ tentar criar esses arquivos no diretório especificado pela variável de ambiente de **TMP** ou no diretório atual se nenhum valor for especificado.  
  
6.  **Não é possível salvar informações de símbolo**  
  
     Esse erro ocorre somente no Visual C\+\+.  A causa provável é que você tiver muitos arquivos abertos ou você não pode fechar ou gravar os arquivos de dados necessários para que o Visual C\+\+ importar os símbolos no script.  Visual C\+\+ tenta usar esses arquivos no diretório especificado pela variável de ambiente de **TMP** ou no diretório atual se nenhum valor for especificado.  
  
7.  **O arquivo de recurso do arquivo de bitmap não estiver no formato 2,03**  
  
     Um bitmap usou um formato anterior à versão 2,03.  O bitmap deve ser convertido ou redesenhado usando o formato da versão 3,00 ou posterior.  
  
8.  **Recurso muito grande**  
  
     Windows 3.1 para um recurso não pode exceder aproximadamente 65000 bytes.  Se o recurso faz, não poderá compilar com o Visual C\+\+ ou o compilador do recurso de linha de comando.  Esse limite não se aplica a cursores, em ícones, os bitmaps, ou a outros recursos backup baseado.  
  
9. **O arquivo de recurso não está no formato 3,00**  
  
     Um cursor ou um ícone usaram um formato anterior à versão 3,00.  O recurso deve ser convertido ou redesenhado usando o formato da versão 3,00 ou posterior.  
  
10. **Pôde abrir o arquivo temporário**  
  
     O compilador do Visual C\+\+ de recursos não pôde abrir um arquivo temporário.  A causa provável é qualquer uma que você não tem permissões de gravação para o diretório ou que o diretório não existe.  O compilador do Visual C\+\+ de recurso tentará usar esses arquivos no diretório especificado pela variável de ambiente de **TMP** ou no diretório atual se nenhum valor for especificado.