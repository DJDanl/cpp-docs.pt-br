---
title: "-Valide-o conjunto de caracteres (validar caracteres compat&#237;vel) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/validate-charset"
  - "validate-charset"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "opção de compilador /Validate-CharSet"
ms.assetid: 50360fd0-4d32-4a4f-95d0-53d38c12ad4c
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Validate-charset (validar caracteres compat&#237;vel)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Valida que o texto do arquivo de origem contém somente caracteres representáveis como UTF\-8.  
  
## Sintaxe  
  
```  
/validate-charset[-]  
```  
  
## Comentários  
 Você pode usar o **\/validate\-charset** opção para validar que o código\-fonte contém apenas o conjunto de caracteres que podem ser representados no caractere de origem e conjunto de caracteres de execução. Esta opção é habilitada automaticamente quando você especifica **\/source\-charset**, **\/execution\-charset**, ou **\/utf\-8** opções do compilador. Você poderá desabilitar explicitamente essa seleção especificando o **\/ validate\-charset \-** opção.  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF\-16 ou UTF\-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você tenha especificado uma página de código usando **\/utf\-8** ou **\/source\-charset** opção. O Visual Studio permite que você salve seu código\-fonte C\+\+ usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [Conjuntos de caracteres](../../cpp/character-sets2.md) na documentação do idioma. Para uma lista de identificadores de página de código e nomes de conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/pt-br/5d6fc86a-f205-4d14-bb7c-ecd71682e0fe).  
  
 O Visual Studio usa UTF\-8 como a codificação de caracteres interno durante a conversão entre o conjunto de caracteres de origem e o conjunto de caracteres de execução. Se um caractere no arquivo de origem não pode ser representado no conjunto de caracteres de execução, a conversão UTF\-8 substitui um ponto de interrogação '?' caracteres. O **\/validate\-charset** opção faz com que a compilação relatar um aviso se isso ocorrer.  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o **Propriedades de configuração**, **C\/C\+\+**, **linha de comando** pasta.  
  
3.  Em **Opções avançadas de**, adicione o **\/validate\-charset** opção e especifique a codificação preferencial.  
  
4.  Escolha **OK** para salvar suas alterações.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/Execution\-charset \(definir execução de conjunto de caracteres\)](../../build/reference/execution-charset-set-execution-character-set.md)   
 [\/Source\-charset \(definir fonte de conjunto de caracteres\)](../../build/reference/source-charset-set-source-character-set.md)   
 [\/UTF\-8 \(definir fonte e executável conjuntos de caracteres UTF\-8\)](../Topic/-utf-8%20\(Set%20Source%20and%20Executable%20character%20sets%20to%20UTF-8\).md)