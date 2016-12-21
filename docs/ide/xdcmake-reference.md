---
title: "Refer&#234;ncia XDCMake | Microsoft Docs"
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
  - "xdcmake"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "programa xdcmake"
ms.assetid: 14e65747-d000-4343-854b-8393bf01cbac
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Refer&#234;ncia XDCMake
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

xdcmake.exe é um programa que compila arquivos de .xdc em um arquivo .xml.  Um arquivo de .xdc é criado pelo compilador do Visual C\+\+ para cada arquivo de código\-fonte quando o código é compilado com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) e quando o arquivo de código\-fonte contém os comentários de documentação marcados anterior com marcas XML.  
  
### Para usar xdcmake.exe no ambiente de desenvolvimento Visual Studio  
  
1.  Abrir a caixa de diálogo **Páginas de Propriedade** de projeto.  Para obter detalhes, consulte:[Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md).  
  
2.  Abra a pasta de **Propriedades de Configuração** .  
  
3.  Clique na página de propriedades de **Comentários de documento XML** .  
  
> [!NOTE]
>  as opções de xdcmake.exe na linha de comando diferem das opções quando xdcmake.exe é usado no ambiente de desenvolvimento \(páginas de propriedades\).  Para obter informações sobre como usar xdcmake.exe no ambiente de desenvolvimento, consulte [Páginas de propriedade da ferramenta geradora de documento XML](../Topic/XML%20Document%20Generator%20Tool%20Property%20Pages.md).  
  
## Sintaxe  
 xdcmake `input_filename options`  
  
## Parâmetros  
 where:  
  
 `input_filename`  
 O nome de arquivo de arquivos de .xdc usados como entrada a xdcmake.exe.  Especifique um ou mais arquivos de .xdc ou use \*.xdc para usar todos os arquivos de .xdc no diretório atual.  
  
 `options`  
 Zero ou mais dos seguintes:  
  
|Opção|Descrição|  
|-----------|---------------|  
|\/? \/help,|Ajuda de exibição para xdcmake.exe.|  
|\/assembly:*nome de arquivo*|Permite que você especifique o valor da marca de \<assembly\> no arquivo .xml.  Por padrão, o valor da marca de \<assembly\> é o mesmo que o nome do arquivo .xml.|  
|\/nologo|Elimina a notificação de direitos autorais.|  
|\/out:*nome de arquivo*|Permite que você especifique o nome do arquivo .xml.  Por padrão, o nome do arquivo .xml é o nome de arquivo do primeiro arquivo .xdc processado por xdcmake.exe.|  
  
## Comentários  
 O Visual Studio automaticamente invocará xdcmake.exe ao criar um projeto.  Você também pode chamar xdcmake.exe na linha de comando.  
  
 Consulte [Marcas recomendadas para comentários de documentação](../Topic/Recommended%20Tags%20for%20Documentation%20Comments%20\(Visual%20C++\).md) para obter mais informações sobre como adicionar comentários de documentação para arquivo de código\-fonte.  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)