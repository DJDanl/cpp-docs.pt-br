---
title: "-execu&#231;&#227;o-charset (conjunto de caracteres do conjunto de execu&#231;&#227;o) | Microsoft Docs"
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
  - "execution-charset"
  - "/execution-charset"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "opção de compilador /Execution-CharSet"
  - "-execução-opção de compilador charset"
ms.assetid: 0e02f487-2236-45bc-95f3-5760933a8f96
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Execution-charset (definir execu&#231;&#227;o de conjunto de caracteres)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que você especifique o caractere de execução definido para o executável.  
  
## Sintaxe  
  
```  
/execution-charset:[IANA_name|.CPID]  
```  
  
## Arguments  
 **IANA\_name**  
 Nome do conjunto de caracteres de definido IANA.  
  
 **CPID**  
 O identificador de página de código.  
  
## Comentários  
 Você pode usar o **\/execution\-charset** opção para especificar um conjunto de caracteres de execução. O conjunto de caracteres de execução é a codificação usada para o texto do programa que a entrada para a fase de compilação após todas as etapas de pré\-processamento. Esse conjunto de caracteres é usado para a representação interna de qualquer cadeia de caracteres ou literais de caracteres no código compilado. Defina essa opção para especificar o conjunto de caracteres estendidos de execução para usar quando os arquivos de origem incluem caracteres que não são representáveis no conjunto de caracteres de execução básico. Você pode usar qualquer IANA ou conjunto de caracteres ISO nome ou um ponto \(.\) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres para usar. Para uma lista de identificadores de página de código e nomes de conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/pt-br/5d6fc86a-f205-4d14-bb7c-ecd71682e0fe).  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF\-16 ou UTF\-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você tenha especificado um conjunto de caracteres nome ou páginas de código usando o **\/source\-charset** opção ou **\/utf\-8** opção. O Visual Studio permite que você salve seu código\-fonte C\+\+ usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [Conjuntos de caracteres](../../cpp/character-sets2.md) na documentação do idioma.  
  
 Se você deseja definir o conjunto de caracteres de origem e o conjunto de caracteres de execução para UTF\-8, você pode usar o **\/utf\-8** opção de compilador como um atalho. É equivalente a especificar **\/origem\-charset:utf\-\/execution 8\-charset:utf\-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **\/validate\-charset** opção por padrão.  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o **Propriedades de configuração**, **C\/C\+\+**, **linha de comando** pasta.  
  
3.  Em **Opções avançadas de**, adicione o **\/execution\-charset** opção e especifique a codificação preferencial.  
  
4.  Escolha **OK** para salvar suas alterações.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/Source\-charset \(definir fonte de conjunto de caracteres\)](../../build/reference/source-charset-set-source-character-set.md)   
 [\/UTF\-8 \(definir fonte e executável conjuntos de caracteres UTF\-8\)](../Topic/-utf-8%20\(Set%20Source%20and%20Executable%20character%20sets%20to%20UTF-8\).md)   
 [\/Validate\-charset \(validar caracteres compatível\)](../../build/reference/validate-charset-validate-for-compatible-characters.md)