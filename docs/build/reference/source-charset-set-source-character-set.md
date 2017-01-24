---
title: "-origem-charset (conjunto de caracteres do conjunto de origem) | Microsoft Docs"
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
  - "source-charset"
  - "/source-charset"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "opção de compilador /Execution-CharSet"
ms.assetid: d3c5bf7f-526d-4ee4-acc5-c1a02a4fc481
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Source-charset (definir fonte de conjunto de caracteres)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que você especifique o caractere de fonte definida para o executável.  
  
## Sintaxe  
  
```  
/source-charset:[IANA_name|.CPID]  
```  
  
## Arguments  
 **IANA\_name**  
 Nome do conjunto de caracteres de definido IANA.  
  
 **CPID**  
 O identificador de página de código como um número decimal.  
  
## Comentários  
 Você pode usar o **\/source\-charset** opção para especificar um caractere fonte estendido definido para usar quando os arquivos de origem incluem caracteres que não são representados no conjunto de caracteres de origem básico. O conjunto de caracteres de origem é a codificação usada para interpretar o texto de origem do programa para a representação interna usada como entrada para as fases de pré\-processamento antes da compilação. A representação interna é convertida para o conjunto de caracteres de execução para armazenar valores de cadeia de caracteres e caracteres no executável. Você pode usar qualquer IANA ou conjunto de caracteres ISO nome ou um ponto \(.\) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres para usar. Para uma lista de identificadores de página de código e nomes de conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/pt-br/5d6fc86a-f205-4d14-bb7c-ecd71682e0fe).  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF\-16 ou UTF\-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especifique um conjunto de caracteres nome ou páginas de código usando o **\/source\-charset** opção. O Visual Studio permite que você salve seu código\-fonte C\+\+ usando qualquer uma das várias codificações de caracteres. Para obter mais informações sobre conjuntos de caracteres de origem e de execução, consulte [Conjuntos de caracteres](../../cpp/character-sets2.md) na documentação do idioma.  
  
 O conjunto de caracteres de origem que você fornecer deve mapear os caracteres ASCII de 7 bits para os mesmos pontos de código no seu conjunto de caracteres, ou muitos erros de compilação provavelmente a seguir. O conjunto de caracteres de origem também deve ser podem ser mapeado para o caractere Unicode estendido definido pode ser codificado por UTF\-8. Caracteres que não pode ser codificadas em UTF\-8 são representados por um substituto específico da implementação. O compilador da Microsoft usa um ponto de interrogação para esses caracteres.  
  
 Se você deseja definir o conjunto de caracteres de origem e o conjunto de caracteres de execução para UTF\-8, você pode usar o **\/utf\-8** opção de compilador como um atalho. É equivalente a especificar **\/origem\-charset:utf\-\/execution 8\-charset:utf\-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **\/validate\-charset** opção por padrão.  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o **Propriedades de configuração**, **C\/C\+\+**, **linha de comando** pasta.  
  
3.  Em **Opções avançadas de**, adicione o **\/source\-charset** opção e especifique a codificação preferencial.  
  
4.  Escolha **OK** para salvar suas alterações.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/Execution\-charset \(definir execução de conjunto de caracteres\)](../../build/reference/execution-charset-set-execution-character-set.md)   
 [\/UTF\-8 \(definir fonte e executável conjuntos de caracteres UTF\-8\)](../Topic/-utf-8%20\(Set%20Source%20and%20Executable%20character%20sets%20to%20UTF-8\).md)   
 [\/Validate\-charset \(validar caracteres compatível\)](../../build/reference/validate-charset-validate-for-compatible-characters.md)