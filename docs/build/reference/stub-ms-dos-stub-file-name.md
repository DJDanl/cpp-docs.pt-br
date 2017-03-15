---
title: "/STUB (nome de arquivo stub do MS-DOS) | Microsoft Docs"
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
  - "/stub"
  - "VC.Project.VCLinkerTool.DosStub"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /STUB"
  - "opção de vinculador de nome de arquivo stub MS-DOS"
  - "opção de vinculador STUB"
  - "opção de vinculador -STUB"
  - "Win32 [C++], anexando programa stub MS-DOS"
  - "API do Windows [C++], anexando programa stub MS-DOS"
ms.assetid: 65221ffe-4f9a-4a14-ac69-3cfb79b40b5f
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /STUB (nome de arquivo stub do MS-DOS)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/STUB:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 Um aplicativo MS\-DOS.  
  
## Comentários  
 A opção \/STUB anexa um programa de stub MS\-DOS para um programa do Win32.  
  
 Um programa de stub é invocado se o arquivo é executado no MS\-DOS.  Exibe uma mensagem geralmente apropriado; no entanto, qualquer aplicativo válida do MS\-DOS pode ser um programa de stub.  
  
 Especifique *um nome de arquivo* para o programa de stub depois de dois\-pontos \(:\) na linha de comando.  O vinculador verifica o *nome de arquivo* e emite uma mensagem de erro se o arquivo não é um executável.  O programa deve ser um arquivo; .exe um arquivo .com é válida para um programa de stub.  
  
 Se essa opção não for usada, o vinculador anexa um programa padrão de stub que emita a seguinte mensagem:  
  
```  
This program cannot be run in MS-DOS mode.  
```  
  
 Ao criar um driver de dispositivo virtual, *o nome de arquivo* permite que o usuário especifica um nome de arquivo que contém uma estrutura de IMAGE\_DOS\_HEADER \(definida em WINNT.H\) a ser usado em VXD, em vez do cabeçalho padrão.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)