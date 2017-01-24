---
title: "Erro das Ferramentas de Vinculador LNK2005 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2005"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2005"
ms.assetid: d9587adc-68be-425c-8a30-15dbc86717a4
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2005
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo já definido no objeto  
  
 O `symbol` determinado, exibido na sua forma decorada, foi definido por multiplicação.  
  
 Para obter mais informações, consulte os artigos da Base de Conhecimento:  
  
-   "LNK2005 Erros Quando as Bibliotecas do Tempo de Execução C de Link são Vinculadas Antes de Bibliotecas MFC" \(Q148652\)  
  
-   "Operador de Exclusão Sobrecarregado Global Causa LNK2005" \(Q140440\)  
  
-   "LNK2005 Erros em Novo e Excluir ao Definir \_ATL\_MIN\_CRT" \(Q184235\).  
  
 Os artigos da Base de Conhecimento estão disponíveis no CD\-ROM da Biblioteca MSDN ou em [http:\/\/support.microsoft.com\/search](http://support.microsoft.com/search).  
  
 Esse erro é seguido por um erro fatal [LNK1169](../Topic/Linker%20Tools%20Error%20LNK1169.md).  
  
### Para corrigir verificando as possíveis causas a seguir  
  
1.  Combinando bibliotecas estáticas e dinâmicas ao mesmo em que também usa [\/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
2.  O símbolo é uma função empacotada \(criada compilando com [\/Gy](../../build/reference/gy-enable-function-level-linking.md)\) e foi incluído em mais de um arquivo, mas alterado entre compilações.  Recompile todos os arquivos que incluem `symbol`.  
  
3.  O símbolo é definido de maneira diferente em dois objetos do membro em bibliotecas diferentes e os dois objetos do membro foram usados.  
  
4.  Um absoluto é definido duas vezes, com um valor diferente em cada definição.  
  
5.  Um arquivo de cabeçalho declarado e uma variável definida.  As possíveis soluções incluem:  
  
    -   Declarar a variável em .h: `extern BOOL MyBool;` e atribuí\-la a um arquivo .c ou .cpp: `BOOL MyBool = FALSE;`.  
  
    -   Declarar a variável [static](../../misc/static-cpp.md).  
  
    -   Declarar a variável [selectany](../../cpp/selectany.md).  
  
6.  Se uuid.lib for usado em combinação com outros arquivos .lib que definam GUIDs \(por exemplo, oledb.lib e adsiid.lib\).  Por exemplo:  
  
    ```  
    oledb.lib(oledb_i.obj) : error LNK2005: _IID_ITransactionObject  
    already defined in uuid.lib(go7.obj)  
    ```  
  
     Para corrigir, adicione [\/FORCE:MULTIPLE](../../build/reference/force-force-file-output.md) às opções de linha de comando do vinculador e verifique se uuid.lib é a primeira biblioteca mencionada.