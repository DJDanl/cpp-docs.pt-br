---
title: Usando mapeamentos de texto genérico
description: Uma introdução aos mapeamentos específicos da Microsoft para tipos de dados, rotinas e outros objetos no tempo de execução C.
ms.topic: conceptual
ms.date: 11/04/2016
f1_keywords:
- _UNICODE
helpviewer_keywords:
- _TXCHAR type
- TINT type
- _TCHAR type
- TSCHAR type
- TEXT type
- TCHAR type
- TCHAR.H data types, mappings defined in
- generic-text data types
- _TINT type
- TUCHAR type
- _UNICODE constant
- TXCHAR type
- generic-text mappings
- _TSCHAR type
- T type
- mappings, generic-text
- _TUCHAR type
- MBCS data type
- _MBCS data type
- _TEXT type
- UNICODE constant
- _T type
ms.assetid: 2848121c-e51f-4b9b-a2e6-833ece4b0cb3
ms.openlocfilehash: ea3b1eef413a0d9f52e81795c04424d533b83504
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590102"
---
# <a name="using-generic-text-mappings"></a>Usando mapeamentos de texto genérico

**Específico da Microsoft**

Para simplificar o desenvolvimento de código para vários mercados internacionais, a biblioteca de tempo de execução da Microsoft fornece mapeamentos de "texto genérico" específico da Microsoft para vários tipos de dados, rotinas e outros objetos. Esses mapeamentos são definidos em TCHAR. H. Você pode usar esses mapeamentos de nome para escrever código genérico que pode ser compilado para qualquer um dos três tipos de conjuntos de caracteres: ASCII (SBCS), MBCS ou Unicode, dependendo de uma constante de manifesto que você define usando uma instrução `#define`. Mapeamentos de texto genérico são extensões da Microsoft não compatíveis com ANSI.

### <a name="preprocessor-directives-for-generic-text-mappings"></a>Diretivas de pré-processador para mapeamentos de texto genérico

|#define|Versão compilada|Exemplo|
|--------------|----------------------|-------------|
|`_UNICODE`|Unicode (caracteres largos)|`_tcsrev` é mapeado para `_wcsrev`|
|`_MBCS`|Caracteres multibyte|`_tcsrev` é mapeado para `_mbsrev`|
|Nenhum (padrão: não há definição de `_UNICODE` ou `_MBCS`)|SBCS (ASCII)|`_tcsrev` é mapeado para `strrev`|

Por exemplo, a função de texto genérico `_tcsrev`, definida em TCHAR.H, é mapeada para `mbsrev`, caso `MBCS` tenha sido definida em seu programa, ou para `_wcsrev`, caso `_UNICODE` tenha sido definida. Caso contrário, `_tcsrev` é mapeada para `strrev`.

O tipo de dados de texto genérico `_TCHAR` , também definido em TCHAR. H, mapeia para o tipo **`char`** se `_MBCS` estiver definido, para digitar **`wchar_t`** se `_UNICODE` estiver definido, e para digitar **`char`** se nenhuma constante for definida. Outros mapeamentos de tipo de dados são fornecidos em TCHAR. H para conveniência de programação, mas o tipo `_TCHAR` é o mais útil.

### <a name="generic-text-data-type-mappings"></a>Mapeamentos de tipo de dados de texto genérico

|Nome do tipo de dados de texto genérico|SBCS (_UNICODE, _MBCS não definidos)|_MBCS definido|_UNICODE definido|
|----------------------------------|--------------------------------------------|--------------------|-----------------------|
|`_TCHAR`|**`char`**|**`char`**|**`wchar_t`**|
|`_TINT`|**`int`**|**`int`**|`wint_t`|
|`_TSCHAR`|**`signed char`**|**`signed char`**|**`wchar_t`**|
|`_TUCHAR`|**`unsigned char`**|**`unsigned char`**|**`wchar_t`**|
|`_TXCHAR`|**`char`**|**`unsigned char`**|**`wchar_t`**|
|`_T` ou `_TEXT`|Nenhum efeito (removido pelo pré-processador)|Nenhum efeito (removido pelo pré-processador)|`L` (converte o próximo caractere ou a próxima cadeia de caracteres no equivalente em Unicode)|

Para obter uma lista completa de mapeamentos de texto genérico de rotinas, variáveis e outros objetos, consulte [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md).

Os fragmentos de código a seguir ilustram o uso de `_TCHAR` e `_tcsrev` para mapear os modelos MBCS, Unicode e SBCS.

```
_TCHAR *RetVal, *szString;
RetVal = _tcsrev(szString);
```

Se `MBCS` tiver sido definido, o pré-processador mapeia o fragmento anterior para o código a seguir:

```
char *RetVal, *szString;
RetVal = _mbsrev(szString);
```

Se `_UNICODE` tiver sido definido, o pré-processador mapeia o mesmo fragmento para o código a seguir:

```
wchar_t *RetVal, *szString;
RetVal = _wcsrev(szString);
```

Se `_MBCS` ou `_UNICODE` não tiver sido definido, o pré-processador mapeará o fragmento para o código ASCII de byte único, da seguinte maneira:

```
char *RetVal, *szString;
RetVal = strrev(szString);
```

Portanto, você pode escrever, manter e compilar um arquivo de código fonte único para execução com rotinas que sejam específicas para qualquer um dos três tipos de conjuntos de caracteres.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)<br/>
[Mapeamentos de tipo de dados](../c-runtime-library/data-type-mappings.md)<br/>
[Mapeamentos de variável constante e global](../c-runtime-library/constant-and-global-variable-mappings.md)<br/>
[Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)<br/>
[Um exemplo de programa de texto genérico](../c-runtime-library/a-sample-generic-text-program.md)
