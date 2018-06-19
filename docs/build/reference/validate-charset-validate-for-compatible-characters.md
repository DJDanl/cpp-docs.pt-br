---
title: -Validar-charset (validar caracteres compatíveis) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- /validate-charset
- validate-charset
dev_langs:
- C++
helpviewer_keywords:
- /validate-charset compiler option
ms.assetid: 50360fd0-4d32-4a4f-95d0-53d38c12ad4c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0804d9d2714cc8c4f065b6908788c067c34ca44b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377382"
---
# <a name="validate-charset-validate-for-compatible-characters"></a>/Validate-charset (validar caracteres compatível)
Valida que o texto do arquivo de origem contém apenas caracteres representáveis como UTF-8.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/validate-charset[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o **/validate-charset** opção para validar que o código-fonte contém apenas o conjunto de caracteres que podem ser representados no caractere de origem e do conjunto de caracteres de execução. Essa verificação é habilitada automaticamente quando você especificar **/source-charset**, **/execution-charset**, ou **/utf-8** opções do compilador. Você poderá desabilitar explicitamente essa seleção especificando o **/Validate -charset -** opção.  
  
 Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especificou uma página de código usando **/utf-8** ou **/source-charset** opção. O Visual Studio permite que você salve seu código-fonte C++ usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma. Para obter uma lista de identificadores de página de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de página de código](http://msdn.microsoft.com/library/windows/desktop/dd317756).  
  
 O Visual Studio usa UTF-8 como a codificação de caracteres interna durante a conversão entre o conjunto de caracteres de origem e o conjunto de caracteres de execução. Se um caractere no arquivo de origem não pode ser representado no conjunto de caracteres de execução, a conversão de UTF-8 substitui um ponto de interrogação '?' caracteres. O **/validate-charset** opção faz com que a compilação relatar um aviso se isso ocorrer.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.  
  
3.  Em **opções avançadas de**, adicione o **/validate-charset** opção e especifique a codificação preferencial.  
  
4.  Escolha **Okey** para salvar suas alterações.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Execution-charset (defina a execução do conjunto de caracteres)](../../build/reference/execution-charset-set-execution-character-set.md)   
 [/Source-charset (definir fonte do conjunto de caracteres)](../../build/reference/source-charset-set-source-character-set.md)   
 [/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](../../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)