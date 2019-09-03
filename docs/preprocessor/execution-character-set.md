---
title: execution_character_set pragma
ms.date: 08/29/2019
f1_keywords:
- execution_character_set
- vc-pragma.execution_character_set
helpviewer_keywords:
- pragma execution_character_set
ms.assetid: 32248cbc-7c92-4dca-8442-230c052b53ad
ms.openlocfilehash: 0c2c812f27634f397af91eace7a41c0e71c1eb99
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218630"
---
# <a name="execution_character_set-pragma"></a>execution_character_set pragma

Especifica o conjunto de caracteres de execução usado para literais de cadeia de caracteres e caracteres. Essa diretiva não é necessária para literais marcados com o `u8` prefixo.

## <a name="syntax"></a>Sintaxe

> **#pragma execution_character_set (** "*destino*" **)**

### <a name="parameters"></a>Parâmetros

*alvo*\
Especifica o conjunto de caracteres de execução de destino. Atualmente, o único conjunto de execuções de destino com suporte é "UTF-8".

## <a name="remarks"></a>Comentários

Essa diretiva de compilador está obsoleta a partir do Visual Studio 2015 atualização 2. Recomendamos que você use as `/execution-charset:utf-8` opções `/utf-8` do compilador ou junto com o `u8` uso do prefixo em caracteres estreitos e literais de cadeia de caracteres que contêm caracteres estendidos. Para obter mais informações sobre `u8` o prefixo, consulte cadeias de caracteres [e literais de caracteres](../cpp/string-and-character-literals-cpp.md). Para obter mais informações sobre as opções do compilador, consulte [/Execution-charset (definir conjunto de caracteres de execução)](../build/reference/execution-charset-set-execution-character-set.md) e [/UTF-8 (defina conjuntos de caracteres de origem e executáveis como UTF-8)](../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md).

A `#pragma execution_character_set("utf-8")` diretiva informa ao compilador para codificar literais de caracteres estreitos e de cadeias de caracteres estreitas em seu código-fonte como UTF-8 no executável. Essa codificação de saída é independente da codificação de arquivo de origem usada.

Por padrão, o compilador codifica caracteres estreitos e cadeias estreitas usando a página de código atual como o conjunto de caracteres de execução. Isso significa que caracteres Unicode ou DBCS em um literal que estão fora do intervalo da página de código atual são convertidos para o caractere de substituição padrão na saída. Os caracteres Unicode e DBCS são truncados para seu byte de ordem inferior. Isso certamente não é o que você pretende. Você pode especificar a codificação UTF-8 para literais no arquivo de origem usando um `u8` prefixo. O compilador passa essas cadeias de caracteres codificadas em UTF-8 para a saída inalterada. Literais de caracteres estreitos prefixados usando U8 devem caber em um byte ou são truncados na saída.

Por padrão, o Visual Studio usa a página de código atual como o conjunto de caracteres de origem usado para interpretar seu código-fonte para saída. Quando um arquivo é lido no, o Visual Studio o interpreta de acordo com a página de código atual, a menos que a página de código do arquivo tenha sido definida ou a menos que uma marca de ordem de byte (BOM) ou caracteres UTF-16 sejam detectadas no início do arquivo. Como o UTF-8 não pode ser definido como a página de código atual, quando a detecção automática encontra arquivos de origem codificados como UTF-8 sem uma BOM, o Visual Studio pressupõe que eles são codificados usando a página de código atual. Os caracteres no arquivo de origem que estão fora do intervalo da página de código especificada ou detectada automaticamente podem causar erros e avisos do compilador.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a \_ \_palavra-chave pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[/Execution-charset (definir conjunto de caracteres de execução)](../build/reference/execution-charset-set-execution-character-set.md)\
[/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)
