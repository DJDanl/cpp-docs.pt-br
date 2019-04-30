---
title: execution_character_set
ms.date: 10/18/2018
f1_keywords:
- execution_character_set
- vc-pragma.execution_character_set
helpviewer_keywords:
- pragma execution_character_set
ms.assetid: 32248cbc-7c92-4dca-8442-230c052b53ad
ms.openlocfilehash: bd31e8e91a1bcbfa6ace9b47fa2b13dd945adb20
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389574"
---
# <a name="executioncharacterset"></a>execution_character_set

Especifica o conjunto de caracteres de execução usado para a cadeia de caracteres literais. Essa diretiva não é necessária para literais marcados com o prefixo u8.

## <a name="syntax"></a>Sintaxe

```
#pragma execution_character_set("target")
```

### <a name="parameters"></a>Parâmetros

*target*<br/>
Especifica o conjunto de caracteres de execução de destino. Atualmente, a execução de destino somente definir com suporte é "utf-8".

## <a name="remarks"></a>Comentários

Essa diretiva de compilador é obsoleta a partir do Visual Studio 2015 atualização 2. É recomendável que você use o `/execution-charset:utf-8` ou `/utf-8` opções do compilador junto com usando o `u8` prefixo em estreitas literais de caracteres e cadeia de caracteres que contiverem caracteres estendidos. Para obter mais informações sobre o `u8` prefixo, consulte [cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md). Para obter mais informações sobre as opções do compilador, consulte [/execution-charset (definir execução de conjunto de caracteres)](../build/reference/execution-charset-set-execution-character-set.md) e [/utf-8 (Definir origem e executáveis conjuntos para UTF-8 de caracteres)](../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md).

O `#pragma execution_character_set("utf-8")` diretiva instrui o compilador a codificação de caractere estreito e literais de cadeia de caracteres estreita no seu código-fonte como UTF-8 no executável. Essa codificação de saída é independente da codificação de arquivo de origem usada.

Por padrão, o compilador codifica caracteres estreitos e cadeias de caracteres estreitas, usando a página de código atual como o conjunto de caracteres de execução. Isso significa que os caracteres Unicode ou DBCS em um literal que estão fora do intervalo de página de código atual são convertidos para o caractere de substituição padrão na saída. Caracteres Unicode e DBCS é truncado para seu byte de ordem inferior. Isso é certamente não o que você pretende. Você pode especificar a codificação UTF-8 para literais no arquivo de origem usando um `u8` prefixo. O compilador passa essas cadeias de caracteres codificados em UTF-8 para a saída inalteradas. Literais de caractere estreito prefixados usando u8 devem se ajustar em um byte, ou eles são truncados na saída.

Por padrão, o Visual Studio usa a página de código atual como o conjunto de caracteres de origem usado para interpretar o código-fonte para a saída. Quando um arquivo é lido no, o Visual Studio o interpreta acordo com a página de código atual, a menos que a página de código do arquivo foi definida ou a menos que uma marca de ordem de byte (BOM) ou caracteres UTF-16 são detectados no início do arquivo. Como UTF-8 não pode ser definida como a página de código atual, quando a detecção automática encontra os arquivos de origem codificados como UTF-8 sem uma BOM, o Visual Studio pressupõe que eles são codificados usando a página de código atual. Caracteres no arquivo de origem que estão fora do intervalo especificado ou automaticamente detectados página de código pode causar erros e avisos do compilador.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a \_ \_palavra-chave de Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)<br/>
[/Execution-charset (definir execução de conjunto de caracteres)](../build/reference/execution-charset-set-execution-character-set.md)<br/>
[/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)