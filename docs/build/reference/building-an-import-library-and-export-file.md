---
title: "Compilando uma biblioteca de importa&#231;&#227;o e um arquivo de exporta&#231;&#227;o | Microsoft Docs"
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
  - "VC.Project.VCLibrarianTool.ModuleDefinitionFile"
  - "VC.Project.VCLibrarianTool.ExportNamedFunctions"
  - "VC.Project.VCLibrarianTool.GenerateDebug"
  - "VC.Project.VCLibrarianTool.ForceSymbolReferences"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .lib"
  - "Opção /DEF (gerenciador de biblioteca)"
  - "Opção /EXPORT (gerenciador de biblioteca)"
  - "Opção /INCLUDE (gerenciador de biblioteca)"
  - "Opção /OUT (gerenciador de biblioteca)"
  - "opção de gerenciador de biblioteca DEF"
  - "opção de gerenciador de biblioteca -DEF"
  - "arquivos EXP"
  - "opção de gerenciador de biblioteca EXPORT"
  - "opção de gerenciador de biblioteca -EXPORT"
  - "exportando dados"
  - "exportando dados, exportar arquivos (.exp)"
  - "importar bibliotecas, compilando"
  - "opção de gerenciador de biblioteca INCLUDE"
  - "opção de gerenciador de biblioteca -INCLUDE"
  - "opção de gerenciador de biblioteca OUT"
  - "opção de gerenciador de biblioteca -OUT"
ms.assetid: 2fe4f30a-1dd6-4b05-84b5-0752e1dee354
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilando uma biblioteca de importa&#231;&#227;o e um arquivo de exporta&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para criar uma biblioteca uma importação e exportação do arquivo, use a seguinte sintaxe:  
  
```  
LIB /DEF[:deffile] [options] [objfiles] [libraries]  
```  
  
 Quando \/DEF é especificado, o LIB cria os arquivos de saída das especificações de exportação que são transmitidas no comando de LIB.  Há três métodos para especificar a exportações, listados na ordem recomendado para uso:  
  
1.  Uma definição de **\_\_declspec\(dllexport\)** em uma *de objfiles* ou *bibliotecas*  
  
2.  Uma especificação de \/EXPORT:*nome* na linha de comando de LIB  
  
3.  Uma definição em uma instrução de **EXPORTS** em `deffile`  
  
 Estes são os mesmos métodos que você usa para especificar exporta ao vincular um programa exportando.  Um programa pode usar mais de um método.  Você pode especificar partes do comando de LIB \(como várias *objfiles* ou especificações de \/EXPORT\) em um arquivo de comando do LIB, exatamente como você pode em um comando de LINK.  
  
 As opções a seguir se aplicam a criar uma biblioteca de importação e exportam\-se o arquivo:  
  
 \/OUT: *importação*  
 Substitui o nome do arquivo de saída padrão para a biblioteca *de importação* que está sendo criada.  Quando \/OUT não for especificado, o nome padrão é o nome de base do primeiro arquivo ou biblioteca do objeto no comando de LIB e na extensão .lib.  O arquivo de exportação é com o mesmo nome de base que a biblioteca de importação e a extensão .exp.  
  
 \/EXPORT: *entryname**internalname*\[\=\] \[, @ `ordinal`**NONAME**\] \[,\] \[,\] **DADOS**  
 Exporta uma função do programa para permitir que outros programas chame a função.  Você também pode exportar os dados \(usando a palavra\-chave de **DADOS** \).  Exporta as são normalmente definidas em uma DLL.  
  
 *O entryname* é o nome do item da função ou de dados como deve ser usada pelo programa de chamada.  Opcionalmente, você pode especificar *o internalname* como a função conhecida no programa de definição; por padrão, o *internalname* é o mesmo que o *entryname*.  `ordinal` especifica um índice na tabela de exportação no intervalo de 1 a 65.535; se você não especificar `ordinal`, o LIB atribui um.  A palavra\-chave de **NONAME** exporta a função apenas como um ordinal, sem *um entryname*.  A palavra\-chave de **DADOS** é usado para exportar objetos somente de dados.  
  
 \/INCLUDE: `symbol`  
 Adiciona o símbolo especificado na tabela de símbolo.  Essa opção é útil para forçar o uso de um objeto da biblioteca que de outra forma não serão incluídos.  
  
 Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu .dll, você deve transmitir o mesmo conjunto de arquivos de objeto ao criar o .dll, como é passada para criar a biblioteca de importação.  
  
## Consulte também  
 [Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md)