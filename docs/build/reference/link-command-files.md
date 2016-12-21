---
title: "Arquivos de comando LINK | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "link"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de comando [C++]"
  - "arquivos de comando [C++], LINK"
  - "ferramenta LINK [C++]"
  - "ferramenta LINK [C++], sintaxe de linha de comando"
  - "sintaxe, arquivos de comando LINK"
  - "arquivos de texto, transferindo argumentos para LINK"
ms.assetid: 7154511c-32b9-4e5b-a515-3922fa9de48e
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos de comando LINK
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode passar argumentos de linha de comando ao LINK na forma de um arquivo de comando.  Para especificar um arquivo de comando ao vinculador, use a seguinte sintaxe:  
  
```  
LINK @commandfile  
```  
  
 `commandfile` é o nome de um arquivo de texto.  Nenhum espaço ou a guia são permitidos entre o sinal de arroba \(@\) e o nome do arquivo.  Não há nenhuma extensão padrão; você deve especificar o nome de arquivo completo, incluindo qualquer extensão.  Os curingas não podem ser usadas.  Você pode especificar um caminho relativo ou absoluto um com o nome do arquivo.  O LINK não usa uma variável de ambiente para procurar o arquivo.  
  
 No arquivo de comando, os argumentos podem ser separados por espaços ou por tabulações \(como na linha de comando\) e por caracteres de nova linha.  
  
 Você pode especificar toda ou parte da linha de comando em um arquivo de comando.  Você pode usar mais de um arquivo de comando em um comando de LINK.  O LINK aceita comando\- Arquivo conectado como se fosse especificado naquele local na linha de comando.  Os arquivos de comando não podem ser aninhados.  Duplica VINCULAR o conteúdo dos arquivos de comando, a menos que a opção de [\/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md) é especificada.  
  
## Exemplo  
 O comando a seguir para criar uma DLL transmite os nomes de arquivos e de bibliotecas de objeto nos arquivos de comando separados e usa um terceiro arquivo de comando para a especificação da opção \/EXPORTS:  
  
```  
link /dll @objlist.txt @liblist.txt @exports.txt  
```  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)