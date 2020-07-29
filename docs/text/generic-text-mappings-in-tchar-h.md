---
title: Mapeamentos de texto genérico em TCHAR. h
ms.date: 11/04/2016
helpviewer_keywords:
- mapping generic-text
- generic-text mappings [C++]
- character sets [C++], generic-text mappings
- Unicode [C++], generic-text mappings
- MBCS [C++], generic-text mappings
- TCHAR.H data types, mapping
- mappings [C++], TCHAR.H
ms.assetid: 01e1bb74-5a01-4093-8720-68b6c1fdda80
ms.openlocfilehash: c317e7d67cc3d086dacbe0f24b0103d389afefda
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217292"
---
# <a name="generic-text-mappings-in-tcharh"></a>Mapeamentos de texto genérico em TCHAR. h

Para simplificar o transporte de código para uso internacional, a biblioteca de tempo de execução da Microsoft fornece mapeamentos de texto genérico específicos da Microsoft para muitos tipos de dados, rotinas e outros objetos. Você pode usar esses mapeamentos, que são definidos em TCHAR. h, para escrever código genérico que pode ser compilado para conjuntos de caracteres de byte único, multibyte ou Unicode, dependendo de uma constante de manifesto que você definir usando uma `#define` instrução. Mapeamentos de texto genérico são extensões da Microsoft não compatíveis com ANSI.

Usando o TCHAR. h, você pode criar um conjunto de caracteres de byte único (MBCS) e aplicativos Unicode a partir das mesmas fontes. TCHAR. h define as macros (que têm o prefixo `_tcs` ), com as definições de pré-processador corretas, mapear para `str` , `_mbs` ou `wcs` funções, conforme apropriado. Para criar MBCS, defina o símbolo `_MBCS` . Para criar o Unicode, defina o símbolo `_UNICODE` . Para criar um aplicativo de byte único, defina nenhum (o padrão). Por padrão, o `_UNICODE` é definido para aplicativos MFC.

O `_TCHAR` tipo de dados é definido condicionalmente em TCHAR. h. Se o símbolo `_UNICODE` for definido para sua compilação, `_TCHAR` é definido como **`wchar_t`** ; caso contrário, para compilações de byte único e MBCS, ele é definido como **`char`** . ( **`wchar_t`** o tipo de dados de caractere largo Unicode básico é a contraparte de 16 bits para um de 8 bits **`signed char`** .) Para aplicativos internacionais, use a `_tcs` família de funções, que opera em `_TCHAR` unidades, não em bytes. Por exemplo, `_tcsncpy` cópias `n` `_TCHARs` , não `n` bytes.

Como algumas funções de manipulação de cadeia de caracteres de conjunto de caracteres de byte único (SBCS) assumem parâmetros (assinados) **`char*`** , um aviso de incompatibilidade de tipo de compilador ocorre quando `_MBCS` é definido. Há três maneiras de evitar esse aviso:

1. Use as conversões de função embutida com segurança de tipo em TCHAR. h. Esse é o comportamento padrão.

1. Use as macros diretas em TCHAR. h definindo `_MB_MAP_DIRECT` na linha de comando. Se você fizer isso, você deverá realizar a correspondência de tipos manualmente. Esse é o método mais rápido, mas não é de tipo seguro.

1. Use as conversões da função de biblioteca vinculada estaticamente de tipo seguro em TCHAR. h. Para fazer isso, defina a constante `_NO_INLINING` na linha de comando. Esse é o método mais lento, no entanto, é o mais fortemente tipado.

### <a name="preprocessor-directives-for-generic-text-mappings"></a>Diretivas de pré-processador para mapeamentos de texto genérico

|# definir|Versão compilada|Exemplo|
|---------------|----------------------|-------------|
|`_UNICODE`|Unicode (caracteres largos)|`_tcsrev` é mapeado para `_wcsrev`|
|`_MBCS`|Caracteres multibyte|`_tcsrev` é mapeado para `_mbsrev`|
|Nenhum (o padrão não tem `_UNICODE` nem `_MBCS` definido)|SBCS (ASCII)|`_tcsrev` é mapeado para `strrev`|

Por exemplo, a função de texto genérico `_tcsrev` , que é definida em TCHAR. h, é mapeada para `_mbsrev` se você definiu `_MBCS` em seu programa ou para `_wcsrev` se você definiu `_UNICODE` . Do contrário, `_tcsrev` é mapeado para `strrev`. Outros mapeamentos de tipo de dados são fornecidos em TCHAR. h para conveniência de programação, mas `_TCHAR` é o mais útil.

### <a name="generic-text-data-type-mappings"></a>Mapeamentos de tipo de dados de texto genérico

|Texto genérico<br /> Nome do tipo de dados|_UNICODE &<br /> _MBCS não definido|_MBCS<br /> Definido|_UNICODE<br /> Definido|
|--------------------------------------|----------------------------------------|------------------------|---------------------------|
|`_TCHAR`|**`char`**|**`char`**|**`wchar_t`**|
|`_TINT`|**`int`**|**`unsigned int`**|`wint_t`|
|`_TSCHAR`|**`signed char`**|**`signed char`**|**`wchar_t`**|
|`_TUCHAR`|**`unsigned char`**|**`unsigned char`**|**`wchar_t`**|
|`_TXCHAR`|**`char`**|**`unsigned char`**|**`wchar_t`**|
|`_T` ou `_TEXT`|Nenhum efeito (removido pelo pré-processador)|Nenhum efeito (removido pelo pré-processador)|`L`(converte o seguinte caractere ou cadeia de caracteres em seu equivalente Unicode)|

Para obter uma lista de mapeamentos de texto genérico de rotinas, variáveis e outros objetos, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) na referência da biblioteca de tempo de execução.

> [!NOTE]
> Não use a `str` família de funções com cadeias de caracteres Unicode, que provavelmente conterá bytes nulos inseridos. Da mesma forma, não use a `wcs` família de funções com cadeias de caracteres MBCS (ou SBCS).

Os fragmentos de código a seguir ilustram o uso de `_TCHAR` e `_tcsrev` para mapear os modelos MBCS, Unicode e SBCS.

```cpp
_TCHAR *RetVal, *szString;
RetVal = _tcsrev(szString);
```

Se `_MBCS` tiver sido definido, o pré-processador mapeará este fragmento para este código:

```cpp
char *RetVal, *szString;
RetVal = _mbsrev(szString);
```

Se `_UNICODE` tiver sido definido, o pré-processador mapeará este fragmento para este código:

```cpp
wchar_t *RetVal, *szString;
RetVal = _wcsrev(szString);
```

Se nem `_MBCS` nem `_UNICODE` tiverem sido definidos, o pré-processador mapeará o fragmento para um código ASCII de byte único, da seguinte maneira:

```cpp
char *RetVal, *szString;
RetVal = strrev(szString);
```

Portanto, você pode escrever, manter e compilar um arquivo de código de fonte única para ser executado com rotinas específicas de qualquer um dos três tipos de conjuntos de caracteres.

## <a name="see-also"></a>Confira também

[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)<br/>
[Usando TCHAR. Tipos de dados H com código de _MBCS](../text/using-tchar-h-data-types-with-mbcs-code.md)
