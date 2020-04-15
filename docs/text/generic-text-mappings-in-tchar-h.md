---
title: Mapeamentos de texto genérico em tchar.h
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
ms.openlocfilehash: bf872df2e6fb49e64a973e8799eef98dec1cb472
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361350"
---
# <a name="generic-text-mappings-in-tcharh"></a>Mapeamentos de texto genérico em tchar.h

Para simplificar o transporte de código para uso internacional, a biblioteca de tempo de execução da Microsoft fornece mapeamentos de texto genérico específicos da Microsoft para muitos tipos de dados, rotinas e outros objetos. Você pode usar esses mapeamentos, que são definidos em tchar.h, para escrever código genérico que pode ser compilado para conjuntos de caracteres `#define` single-byte, multibyte ou Unicode, dependendo de uma constante manifesto que você define usando uma declaração. Mapeamentos de texto genérico são extensões da Microsoft não compatíveis com ANSI.

Usando o tchar.h, você pode criar aplicativos MBCS (Multibyte Character Set, conjunto de caracteres de byte único) e Unicode das mesmas fontes. tchar.h define macros (que `_tcs`têm o prefixo ) que, com `str` `_mbs`as `wcs` definições corretas do pré-processador, mapeiam para , ou funções, conforme apropriado. Para construir o MBCS, defina o símbolo `_MBCS`. Para construir unicode, `_UNICODE`defina o símbolo . Para construir um aplicativo de byte único, defina nenhum (o padrão). Por padrão, `_UNICODE` é definido para aplicações MFC.

O `_TCHAR` tipo de dados é definido condicionalmente em tchar.h. Se o `_UNICODE` símbolo for definido `_TCHAR` para sua compilação, será definido como **wchar_t;** caso contrário, para construções de byte único e MBCS, é definido como **char**. **(wchar_t**, o tipo básico de dados de caracteres de caracteres de amplo Unicode, é a contrapartida de 16 bits para um **char**assinado de 8 bits .) Para aplicações internacionais, `_tcs` utilize a família de `_TCHAR` funções, que operam em unidades, não bytes. Por `_tcsncpy` exemplo, `n` `_TCHARs`cópias, não `n` bytes.

Como algumas funções de manipulação de strings do Single Byte Character Set (SBCS) tomam parâmetros (assinados), `char*` um compilador de tipo incompatível resulta quando `_MBCS` é definido. Há três maneiras de evitar este aviso:

1. Use a função inline de segurança do tipo em tchar.h. Esse é o comportamento padrão.

1. Use as macros diretas em `_MB_MAP_DIRECT` tchar.h definindo na linha de comando. Se você fizer isso, você deverá realizar a correspondência de tipos manualmente. Este é o método mais rápido, mas não é seguro para o tipo.

1. Use a função de biblioteca estáticamente ligada ao tipo em tchar.h. Para fazer isso, defina a constante `_NO_INLINING` na linha de comando. Esse é o método mais lento, no entanto, é o mais fortemente tipado.

### <a name="preprocessor-directives-for-generic-text-mappings"></a>Diretivas de pré-processador para mapeamentos de texto genérico

|# definir|Versão compilada|Exemplo|
|---------------|----------------------|-------------|
|`_UNICODE`|Unicode (caracteres largos)|`_tcsrev` mapeia para `_wcsrev`|
|`_MBCS`|Caracteres multibyte|`_tcsrev` mapeia para `_mbsrev`|
|Nenhum (o padrão `_UNICODE` `_MBCS` não tem nem definido)|SBCS (ASCII)|`_tcsrev` mapeia para `strrev`|

Por exemplo, a função `_tcsrev`texto genérico , que é definida `_mbsrev` em `_MBCS` tchar.h, `_wcsrev` mapeia se você definiu em seu programa, ou se você definiu `_UNICODE`. Do contrário, `_tcsrev` é mapeado para `strrev`. Outros mapeamentos de tipo de dados são fornecidos em `_TCHAR` tchar.h para conveniência de programação, mas é o mais útil.

### <a name="generic-text-data-type-mappings"></a>Mapeamentos de tipo de dados de texto genérico

|Texto genérico<br /> Nome do tipo de dados|& _UNICODE<br /> _MBCS Não Definidos|_MBCS<br /> Definido|_UNICODE<br /> Definido|
|--------------------------------------|----------------------------------------|------------------------|---------------------------|
|`_TCHAR`|**char**|**char**|**Wchar_t**|
|`_TINT`|**int**|**unsigned int**|`wint_t`|
|`_TSCHAR`|**signed char**|**signed char**|**Wchar_t**|
|`_TUCHAR`|**unsigned char**|**unsigned char**|**Wchar_t**|
|`_TXCHAR`|**char**|**unsigned char**|**Wchar_t**|
|`_T` ou `_TEXT`|Nenhum efeito (removido pelo pré-processador)|Nenhum efeito (removido pelo pré-processador)|`L`(converte o seguinte caractere ou string em sua contraparte Unicode)|

Para obter uma lista de mapeamentos de texto genérico de rotinas, variáveis e outros objetos, consulte [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) sinuoso na referência de biblioteca em tempo de execução.

> [!NOTE]
> Não use `str` a família de funções com strings Unicode, que provavelmente contenham bytes nulos incorporados. Da mesma forma, `wcs` não use a família de funções com cordas MBCS (ou SBCS).

Os fragmentos de código a seguir ilustram o uso de `_TCHAR` e `_tcsrev` para mapear os modelos MBCS, Unicode e SBCS.

```cpp
_TCHAR *RetVal, *szString;
RetVal = _tcsrev(szString);
```

Se `_MBCS` tiver sido definido, o pré-processador mapeia este fragmento para este código:

```cpp
char *RetVal, *szString;
RetVal = _mbsrev(szString);
```

Se `_UNICODE` tiver sido definido, o pré-processador mapeia este fragmento para este código:

```cpp
wchar_t *RetVal, *szString;
RetVal = _wcsrev(szString);
```

Se `_MBCS` nem `_UNICODE` foram definidos, o pré-processador mapeia o fragmento para um único byte código ASCII, da seguinte forma:

```cpp
char *RetVal, *szString;
RetVal = strrev(szString);
```

Portanto, você pode escrever, manter e compilar um arquivo de código de código de código único para executar com rotinas específicas para qualquer um dos três tipos de conjuntos de caracteres.

## <a name="see-also"></a>Confira também

[Texto e Cordas](../text/text-and-strings-in-visual-cpp.md)<br/>
[Usando TCHAR. Tipos de dados H com código de _MBCS](../text/using-tchar-h-data-types-with-mbcs-code.md)
