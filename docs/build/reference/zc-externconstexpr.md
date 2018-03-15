---
title: "/ZC:externConstexpr (habilitar variáveis de constexpr de extern) | Microsoft Docs"
ms.custom: 
ms.date: 02/28/2018
ms.technology:
- cpp-tools
ms.topic: article
f1_keywords:
- /Zc:externConstexpr
dev_langs:
- C++
helpviewer_keywords:
- -Zc:externConstexpr compiler option (C++)
- extern constexpr variables (C++)
ms.assetid: 4da5e33a-2e4d-4ed2-8616-bd8f43265c27
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6597bc96609ab051df56886ccc580516986f97ed
ms.sourcegitcommit: eeb2b5ad8d3d22514a7b9bd7d756511b69ae0ccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2018
---
# <a name="zcexternconstexpr-enable-extern-constexpr-variables"></a>/ZC:externConstexpr (variáveis de constexpr extern habilitar)

O **/Zc:externConstexpr** opção de compilador informa ao compilador para estar de acordo com o padrão C++ e permitir a ligação externa para `constexpr` variáveis. Por padrão, o Visual Studio fornece sempre uma `constexpr` variável ligação interna, mesmo se você especificar o `extern` palavra-chave.

## <a name="syntax"></a>Sintaxe

> **/Zc:externConstexpr**[**-**]

## <a name="remarks"></a>Comentários

O **/Zc:externConstexpr** opção de compilador faz com que o compilador aplicar a vinculação externa para as variáveis declaradas usando `extern constexpr`. Em versões anteriores do Visual Studio e, por padrão ou se **/Zc:externConstexpr-** for especificado, o Visual Studio se aplica a vinculação interna para `constexpr` se até mesmo variáveis de `extern` palavra-chave é usada. O **/Zc:externConstexpr** opção está disponível a partir do Visual Studio 2017 atualização 15,6. e é desativada por padrão. O [/ permissivo-](permissive-standards-conformance.md) não habilitar a opção **/Zc:externConstexpr**.

Se um arquivo de cabeçalho contém uma variável declarada `extern constexpr`, ela deve ser marcada [__declspec(selectany)](../../cpp/selectany.md) para mesclar as declarações duplicadas em uma única instância no binário vinculado. Caso contrário, você poderá ver erros de vinculador, por exemplo, LNK2005, violações da definição de uma regra.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Adicionar **/Zc:externConstexpr** ou **/Zc:externConstexpr-** para o **opções adicionais:** painel.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)  
[Palavra-chave auto](../../cpp/auto-keyword.md)