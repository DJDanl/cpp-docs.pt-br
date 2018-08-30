---
title: -source-charset (definir conjunto de caracteres de origem) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- source-charset
- /source-charset
dev_langs:
- C++
helpviewer_keywords:
- /execution-charset compiler option
ms.assetid: d3c5bf7f-526d-4ee4-acc5-c1a02a4fc481
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 722586f3a629535c5ea70c26e5172e6bc7ecb418
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43213074"
---
# <a name="source-charset-set-source-character-set"></a>/Source-charset (Definir origem conjunto de caracteres)
Permite que você especifique o conjunto para o executável de caracteres de origem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/source-charset:[IANA_name|.CPID]  
```  
  
## <a name="arguments"></a>Arguments  
 **IANA_name**  
 Nome do conjunto de caracteres de definido pelo IANA.  
  
 **CPID**  
 O identificador de página de código como um número decimal.  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o **/source-charset** opção para especificar um caractere de origem estendido definido para usar quando os arquivos de origem incluem caracteres que não são representadas no conjunto de caracteres de origem básicos. O conjunto de caracteres de origem é a codificação usada para interpretar o texto de origem do seu programa com a representação interna usada como entrada para as fases de pré-processamento antes da compilação. A representação interna, em seguida, é convertida para o conjunto de caracteres de execução para armazenar valores de cadeia de caracteres e o caractere no executável. Você pode usar qualquer um dos IANA ou nome do conjunto de caracteres ISO ou um ponto (.) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres para usar. Para obter uma lista de identificadores de páginas de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de páginas de código](/windows/desktop/Intl/code-page-identifiers).  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especifique um conjunto de caracteres nome ou páginas de código usando o **/source-charset** opção. Visual Studio permite que você salvar seu código-fonte C++, usando qualquer uma das várias codificações de caracteres. Para obter mais informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.  
  
 O conjunto de caracteres de origem que você fornecer deve mapear os caracteres ASCII de 7 bits para os mesmos pontos de código no seu conjunto de caracteres ou provavelmente muitos erros de compilação a seguir. Seu conjunto de caracteres de origem também deve ser podem ser mapeado para o caractere Unicode estendido definido pode ser codificado por UTF-8. Caracteres que não pode ser codificadas em UTF-8 são representados por um substituto específico da implementação. O compilador Microsoft usa um ponto de interrogação para esses caracteres.  
  
 Se você quiser definir o conjunto de caracteres de origem e o conjunto de caracteres de execução para UTF-8, você pode usar o **/utf-8** opção do compilador como um atalho. Ele equivale à especificação **/origem-charset:utf-/execution 8-charset:utf-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **/validate-charset** opção por padrão.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.  
  
3.  Na **opções avançadas**, adicione o **/source-charset** opção e especifique a codificação preferencial.  
  
4.  Escolher **Okey** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Execution-charset (definir execução de conjunto de caracteres)](../../build/reference/execution-charset-set-execution-character-set.md)   
 [/UTF-8 (Definir origem e executáveis conjuntos de caracteres UTF-8)](../../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)   
 [/validate-charset (validar quanto à presença de caracteres compatíveis)](../../build/reference/validate-charset-validate-for-compatible-characters.md)