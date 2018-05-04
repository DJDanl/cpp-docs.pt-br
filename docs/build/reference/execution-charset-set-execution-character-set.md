---
title: -execução-charset (conjunto de caracteres de execução do conjunto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- execution-charset
- /execution-charset
dev_langs:
- C++
helpviewer_keywords:
- /execution-charset compiler option
- -execution-charset compiler option
ms.assetid: 0e02f487-2236-45bc-95f3-5760933a8f96
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5bffe1e39aa181a6d53784fbb4501bf8f662b221
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="execution-charset-set-execution-character-set"></a>/Execution-charset (defina a execução do conjunto de caracteres)
Permite que você especifique o caractere de execução definida para o executável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/execution-charset:[IANA_name|.CPID]  
```  
  
## <a name="arguments"></a>Arguments  
 **IANA_name**  
 Nome do conjunto de caracteres definida pelo IANA.  
  
 **CPID**  
 O identificador de página de código.  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o **/execution-charset** opção para especificar um conjunto de caracteres de execução. O conjunto de caracteres de execução é a codificação usada para o texto do programa que é de entrada para a fase de compilação depois que todas as etapas de pré-processamento. Este conjunto de caracteres é usado para a representação interna de qualquer cadeia de caracteres ou literais de caracteres no código compilado. Defina essa opção para especificar o conjunto de caracteres estendidos de execução para usar quando os arquivos de origem incluem caracteres que não são representáveis no conjunto de caracteres de execução básico. Você pode usar qualquer IANA ou nome do conjunto de caracteres ISO ou um ponto (.) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres para usar. Para obter uma lista de identificadores de página de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/library/windows/desktop/dd317756).  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especificou um conjunto de caracteres nome ou páginas de código usando o **/source-charset** opção ou **/utf-8** opção. O Visual Studio permite que você salve seu código-fonte C++ usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.  
  
 Se você deseja definir o conjunto de caracteres de origem e o conjunto de caracteres de execução para UTF-8, você pode usar o **/utf-8** opção de compilador como um atalho. É equivalente a especificar **/origem-charset:utf-/execution 8-charset:utf-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **/validate-charset** opção por padrão.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.  
  
3.  Em **opções avançadas de**, adicione o **/execution-charset** opção e especifique a codificação preferencial.  
  
4.  Escolha **Okey** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Source-charset (definir fonte do conjunto de caracteres)](../../build/reference/source-charset-set-source-character-set.md)   
 [/UTF-8 (Definir origem e o executável conjuntos de caracteres UTF-8)](../../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)   
 [/validate-charset (validar quanto à presença de caracteres compatíveis)](../../build/reference/validate-charset-validate-for-compatible-characters.md)