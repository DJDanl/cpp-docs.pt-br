---
title: Mapeamentos de texto genéricos em TCHAR. h | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- tchar.h
dev_langs:
- C++
helpviewer_keywords:
- mapping generic-text
- generic-text mappings [C++]
- character sets [C++], generic-text mappings
- Unicode [C++], generic-text mappings
- MBCS [C++], generic-text mappings
- TCHAR.H data types, mapping
- mappings [C++], TCHAR.H
ms.assetid: 01e1bb74-5a01-4093-8720-68b6c1fdda80
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9769e1af4f9a1aa8c2c347d8724712b52e03bc22
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606483"
---
# <a name="generic-text-mappings-in-tcharh"></a>Mapeamentos de texto genéricos em Tchar.h
Para simplificar o transporte de código para uso internacional, a biblioteca de tempo de execução da Microsoft fornece mapeamentos de texto genérico de específico da Microsoft para muitos tipos de dados, rotinas e outros objetos. Você pode usar esses mapeamentos, que são definidos em TCHAR. h, para escrever código genérico que pode ser compilado para o byte único, vários bytes, ou conjuntos de caracteres Unicode, dependendo da constante de manifesto que você define usando uma `#define` instrução. Mapeamentos de texto genérico são extensões da Microsoft não compatíveis com ANSI.  
  
 Usando o TCHAR. h, você pode criar aplicativos Unicode das mesmas origens de byte único e conjunto de caracteres Multibyte (MBCS). TCHAR. h define as macros (que têm o prefixo `_tcs`) que, com as definições de pré-processador corretas, mapear para `str`, `_mbs`, ou `wcs` funções, conforme apropriado. Para compilar o MBCS, defina o símbolo `_MBCS`. Para compilar o Unicode, defina o símbolo `_UNICODE`. Para criar um aplicativo de byte único, defina nenhum (padrão). Por padrão, `_MBCS` está definido para aplicativos MFC.  
  
 O `_TCHAR` tipo de dados é definido condicionalmente em TCHAR. h. Se o símbolo `_UNICODE` está definido para a compilação `_TCHAR` é definido como **wchar_t**; caso contrário, para byte e compilações MBCS, ele é definido como **char**. (**wchar_t**, o tipo de dados de caracteres largos Unicode básico, é a contraparte de 16 bits um assinado de 8 bits **char**.) Aplicativos internacionais, use o `_tcs` família de funções, que operam em `_TCHAR` unidades, não em bytes. Por exemplo, `_tcsncpy` cópias `n` `_TCHARs`, e não `n` bytes.  
  
 Porque algum tratamento de cadeia de caracteres do conjunto de caractere de Byte único (SBCS) (assinados) de funções `char*` parâmetros, um resultados de aviso de compilador de incompatibilidade de tipo quando `_MBCS` está definido. Há três maneiras de evitar esse aviso:  
  
1.  Use as conversões de função embutidas fortemente tipadas em TCHAR. h. Este é o comportamento padrão.  
  
2.  Use as macros diretas em TCHAR. h definindo `_MB_MAP_DIRECT` na linha de comando. Se você fizer isso, você deverá realizar a correspondência de tipos manualmente. Isso é o método mais rápido, mas não é fortemente tipado.  
  
3.  Use as conversões de função de biblioteca de vinculada estaticamente fortemente tipadas em TCHAR. h. Para fazer isso, defina a constante `_NO_INLINING` na linha de comando. Esse é o método mais lento, no entanto, é o mais fortemente tipado.  
  
### <a name="preprocessor-directives-for-generic-text-mappings"></a>Diretivas de pré-processador para mapeamentos de texto genérico  
  
|# define|Versão compilada|Exemplo|  
|---------------|----------------------|-------------|  
|`_UNICODE`|Unicode (caracteres largos)|`_tcsrev` mapeia para `_wcsrev`|  
|`_MBCS`|Caracteres multibyte|`_tcsrev` mapeia para `_mbsrev`|  
|None (o padrão não possui `_UNICODE` nem `_MBCS` definido)|SBCS (ASCII)|`_tcsrev` mapeia para `strrev`|  
  
 Por exemplo, a função de texto genérico `_tcsrev`, que é definido em TCHAR. h, é mapeado para `_mbsrev` se você tiver definido `_MBCS` em seu programa, ou para `_wcsrev` se você tiver definido `_UNICODE`. Do contrário, `_tcsrev` é mapeado para `strrev`. Outros mapeamentos de tipo de dados são fornecidos em TCHAR. h para conveniência de programação, mas `_TCHAR` é mais útil.  
  
### <a name="generic-text-data-type-mappings"></a>Mapeamentos de tipo de dados de texto genérico  
  
|Texto genérico<br /><br /> Nome do tipo de dados|UNICODE &AMP;<br /><br /> MBCS não definidos|_MBCS<br /><br /> Definido|_UNICODE<br /><br /> Definido|  
|--------------------------------------|----------------------------------------|------------------------|---------------------------|  
|`_TCHAR`|**char**|**char**|**wchar_t**|  
|`_TINT`|**int**|**unsigned int**|`wint_t`|  
|`_TSCHAR`|**char assinada**|**char assinada**|**wchar_t**|  
|`_TUCHAR`|**unsigned char**|**unsigned char**|**wchar_t**|  
|`_TXCHAR`|**char**|**unsigned char**|**wchar_t**|  
|`_T` ou `_TEXT`|Nenhum efeito (removido pelo pré-processador)|Nenhum efeito (removido pelo pré-processador)|`L` (converte o caractere ou cadeia de caracteres a seguir à sua contraparte Unicode)|  
  
 Para obter uma lista de mapeamentos de texto genérico de rotinas, variáveis e outros objetos, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) na referência da biblioteca de tempo de execução.  
  
> [!NOTE]
>  Não use o `str` família de funções com cadeias de caracteres Unicode, que possam conter inseridos bytes nulos. Da mesma forma, não use o `wcs` família de funções com cadeias de caracteres MBCS (ou SBCS).  
  
 Os fragmentos de código a seguir ilustram o uso de `_TCHAR` e `_tcsrev` para mapear os modelos MBCS, Unicode e SBCS.  
  
```  
_TCHAR *RetVal, *szString;  
RetVal = _tcsrev(szString);  
```  
  
 Se `_MBCS` tiver sido definido, o pré-processador mapeia esse fragmento para este código:  
  
```  
char *RetVal, *szString;  
RetVal = _mbsrev(szString);  
```  
  
 Se `_UNICODE` tiver sido definido, o pré-processador mapeia esse fragmento para este código:  
  
```  
wchar_t *RetVal, *szString;  
RetVal = _wcsrev(szString);  
```  
  
 Se nem `_MBCS` nem `_UNICODE` ter sido definido, o pré-processador mapeia o fragmento ao código ASCII de byte único, da seguinte maneira:  
  
```  
char *RetVal, *szString;  
RetVal = strrev(szString);  
```  
  
 Portanto, você pode escrever, manter e compilar um arquivo de código-fonte única para execução com rotinas que são específicas para qualquer um dos três tipos de conjuntos de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Usando tipos de dados TCHAR.H com código _MBCS](../text/using-tchar-h-data-types-with-mbcs-code.md)