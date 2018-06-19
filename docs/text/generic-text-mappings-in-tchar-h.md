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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c7ed29b03a37c9b911a954192152115b1458fd94
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33867097"
---
# <a name="generic-text-mappings-in-tcharh"></a>Mapeamentos de texto genéricos em Tchar.h
Para simplificar o transporte de código para uso internacional, o [!INCLUDE[TLA#tla_ms](../text/includes/tlasharptla_ms_md.md)] biblioteca de tempo de execução fornece [!INCLUDE[TLA#tla_ms](../text/includes/tlasharptla_ms_md.md)]-mapeamentos de texto genérico específicos para muitos tipos de dados, rotinas e outros objetos. Você pode usar esses mapeamentos, que são definidos em TCHAR. h para escrever o código genérico que pode ser compilado para byte único, vários bytes, ou [!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)] caracteres conjuntos, dependendo de uma constante de manifesto que você define usando uma `#define` instrução. Mapeamentos de texto genérico são [!INCLUDE[TLA#tla_ms](../text/includes/tlasharptla_ms_md.md)] extensões que não são [!INCLUDE[vcpransi](../atl-mfc-shared/reference/includes/vcpransi_md.md)] compatível.  
  
 Usando o TCHAR. h, você pode criar um conjunto de caracteres com a Multibyte (MBCS) byte, e [!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)] aplicativos sejam as mesmas fontes. TCHAR. h define as macros (que têm o prefixo `_tcs`) que, com as definições de pré-processador corretas, mapear para `str`, `_mbs`, ou `wcs` funções, conforme apropriado. Para criar MBCS, defina o símbolo `_MBCS`. Para criar [!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)], defina o símbolo `_UNICODE`. Para criar um aplicativo de byte único, defina nenhum (o padrão). Por padrão, `_MBCS` está definido para aplicativos MFC.  
  
 O `_TCHAR` tipo de dados é definido condicionalmente em TCHAR. h. Se o símbolo `_UNICODE` está definido para a compilação, `_TCHAR` é definido como `wchar_t`; caso contrário, para um byte e MBCS compilações, ele é definido como `char`. (`wchar_t`, o tipo de dados de caractere largo Unicode básico, é a contraparte de 16 bits para um assinado de 8 bits `char`.) Aplicativos internacionais, use o `_tcs` família de funções, que operam em `_TCHAR` unidades, não em bytes. Por exemplo, `_tcsncpy` cópias `n` `_TCHARs`, não `n` bytes.  
  
 Como alguns tratamentos de cadeia de caracteres do conjunto de caractere de Byte único (SBCS) funções usam (assinado) `char*` parâmetros, um resultados de aviso de compilador de incompatibilidade de tipo quando `_MBCS` está definido. Há três maneiras de evitar este aviso:  
  
1.  Use as conversões de função embutida fortemente tipado TCHAR. h. Este é o comportamento padrão.  
  
2.  Usar as macros diretas em TCHAR. h definindo `_MB_MAP_DIRECT` na linha de comando. Se você fizer isso, você deverá realizar a correspondência de tipos manualmente. Isso é o método mais rápido, mas não é fortemente tipado.  
  
3.  Use as conversões de função de biblioteca de tipo seguro estaticamente vinculada TCHAR. h. Para fazer isso, defina a constante `_NO_INLINING` na linha de comando. Esse é o método mais lento, no entanto, é o mais fortemente tipado.  
  
### <a name="preprocessor-directives-for-generic-text-mappings"></a>Diretivas de pré-processador para mapeamentos de texto genérico  
  
|# define|Versão compilada|Exemplo|  
|---------------|----------------------|-------------|  
|`_UNICODE`|[!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)] (caractere largo)|`_tcsrev` mapeia para `_wcsrev`|  
|`_MBCS`|Caracteres multibyte|`_tcsrev` mapeia para `_mbsrev`|  
|Nenhum (o padrão não tem `_UNICODE` nem `_MBCS` definido)|SBCS ([!INCLUDE[TLA#tla_ascii](../text/includes/tlasharptla_ascii_md.md)])|`_tcsrev` mapeia para `strrev`|  
  
 Por exemplo, a função de texto genérico `_tcsrev`, que é definido em TCHAR. h, mapeia para `_mbsrev` se você definiu `_MBCS` em seu programa, ou para `_wcsrev` se você definiu `_UNICODE`. Do contrário, `_tcsrev` é mapeado para `strrev`. Outros mapeamentos de tipo de dados são fornecidos em TCHAR. h para conveniência de programação, mas `_TCHAR` é mais útil.  
  
### <a name="generic-text-data-type-mappings"></a>Mapeamentos de tipo de dados de texto genérico  
  
|Texto genérico<br /><br /> Nome do tipo de dados|UNICODE &AMP;<br /><br /> MBCS não definido|_MBCS<br /><br /> Definido|_UNICODE<br /><br /> Definido|  
|--------------------------------------|----------------------------------------|------------------------|---------------------------|  
|`_TCHAR`|`char`|`char`|`wchar_t`|  
|`_TINT`|`int`|`unsigned int`|`wint_t`|  
|`_TSCHAR`|`signed char`|`signed char`|`wchar_t`|  
|`_TUCHAR`|`unsigned char`|`unsigned char`|`wchar_t`|  
|`_TXCHAR`|`char`|`unsigned char`|`wchar_t`|  
|`_T` ou `_TEXT`|Nenhum efeito (removido pelo pré-processador)|Nenhum efeito (removido pelo pré-processador)|`L` (converte o seguinte caractere ou cadeia de caracteres para seus [!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)] correspondente)|  
  
 Para obter uma lista de mapeamentos de texto genérico de rotinas, variáveis e outros objetos, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) na referência de biblioteca de tempo de execução.  
  
> [!NOTE]
>  Não use o `str` família de funções com cadeias de caracteres Unicode, que possam conter inseridos bytes nulos. Da mesma forma, não use o `wcs` família de funções com cadeias de caracteres MBCS (ou SBCS).  
  
 Os fragmentos de código a seguir ilustram o uso de `_TCHAR` e `_tcsrev` para mapeamento MBCS, [!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)]e modelos SBCS.  
  
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
  
 Se nem `_MBCS` nem `_UNICODE` ter sido definido, o pré-processador mapeia o fragmento de byte único [!INCLUDE[TLA#tla_ascii](../text/includes/tlasharptla_ascii_md.md)] de código, da seguinte maneira:  
  
```  
char *RetVal, *szString;  
RetVal = strrev(szString);  
```  
  
 Portanto, você pode escrever, manter e compilar um arquivo de código-fonte única para executar com rotinas que são específicas para qualquer um dos três tipos de conjuntos de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Usando tipos de dados TCHAR.H com código _MBCS](../text/using-tchar-h-data-types-with-mbcs-code.md)