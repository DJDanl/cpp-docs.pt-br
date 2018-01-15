---
title: -origem-charset (conjunto de caracteres de origem do conjunto) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- source-charset
- /source-charset
dev_langs: C++
helpviewer_keywords: /execution-charset compiler option
ms.assetid: d3c5bf7f-526d-4ee4-acc5-c1a02a4fc481
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a4aa81ba41587a183aca921177a62a45229810f1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="source-charset-set-source-character-set"></a>/Source-charset (definir fonte do conjunto de caracteres)
Permite que você especifique o caractere de origem definido para o executável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/source-charset:[IANA_name|.CPID]  
```  
  
## <a name="arguments"></a>Arguments  
 **IANA_name**  
 Nome do conjunto de caracteres definida pelo IANA.  
  
 **CPID**  
 O identificador de página de código como um número decimal.  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o **/source-charset** opção para especificar um caractere de origem estendido definido para usar quando os arquivos de origem incluem caracteres que não são representados no conjunto de caracteres de origem básico. O conjunto de caracteres de origem é a codificação usada para interpretar o texto de origem do programa para a representação interna usada como entrada para as fases de pré-processamento antes da compilação. A representação interna é convertida para o conjunto de caracteres de execução para armazenar valores de cadeia de caracteres e caracteres no executável. Você pode usar qualquer IANA ou nome do conjunto de caracteres ISO ou um ponto (.) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres para usar. Para obter uma lista de identificadores de página de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/library/windows/desktop/dd317756).  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especifique um conjunto de caracteres nome ou páginas de código usando o **/source-charset** opção. O Visual Studio permite que você salve seu código-fonte C++ usando qualquer uma das várias codificações de caracteres. Para obter mais informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets2.md) na documentação do idioma.  
  
 O conjunto de caracteres de origem que você fornecer deve mapear os caracteres ASCII de 7 bits para os mesmos pontos de código no seu conjunto de caracteres, ou muitos erros de compilação têm probabilidade de seguir. O conjunto de caracteres de origem também deve ser podem ser mapeado para o caractere Unicode estendido definido pode ser codificado por UTF-8. Caracteres que não pode ser codificadas em UTF-8 são representados por um substituto específicos de implementação. O compilador da Microsoft usa um ponto de interrogação esses caracteres.  
  
 Se você deseja definir o conjunto de caracteres de origem e o conjunto de caracteres de execução para UTF-8, você pode usar o **/utf-8** opção de compilador como um atalho. É equivalente a especificar **/origem-charset:utf-/execution 8-charset:utf-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **/validate-charset** opção por padrão.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.  
  
3.  Em **opções avançadas de**, adicione o **/source-charset** opção e especifique a codificação preferencial.  
  
4.  Escolha **Okey** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Execution-charset (defina a execução do conjunto de caracteres)](../../build/reference/execution-charset-set-execution-character-set.md)   
 [/UTF-8 (Definir origem e o executável conjuntos de caracteres UTF-8)](../../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)   
 [/Validate-charset (validar caracteres compatível)](../../build/reference/validate-charset-validate-for-compatible-characters.md)