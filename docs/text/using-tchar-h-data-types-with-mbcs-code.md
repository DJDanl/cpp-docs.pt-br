---
title: Usando TCHAR. Tipos de dados H com código MBCS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- tchar.h
- TCHAR
dev_langs:
- C++
helpviewer_keywords:
- mapping generic-text
- generic-text data types [C++]
- generic-text mappings [C++]
- MBCS [C++], generic-text mappings
- TCHAR.H data types, mapping
- mappings [C++], TCHAR.H
ms.assetid: 298583c5-22c3-40f6-920e-9ec96d42abd8
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e80ecd123e3fc47705563156e33f46ecd99a0321
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33858348"
---
# <a name="using-tcharh-data-types-with-mbcs-code"></a>Usando tipos de dados TCHAR.H com código _MBCS
Quando o manifesto constante **MBCS** é definida, uma rotina de texto genérico determinada mapeado para um dos seguintes tipos de rotinas de:  
  
-   Uma rotina SBCS que lida com bytes, caracteres e cadeias de caracteres multibyte. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo **char\***. Por exemplo, `_tprintf` mapeia para `printf`; os argumentos de cadeia de caracteres para `printf` são do tipo **char\***. Se você usar o **TCHAR** tipos de tipo de dados de texto genérico para a cadeia de caracteres, os tipos de parâmetro formal e real para `printf` corresponder porque **TCHAR**\* mapeia para **char\***.  
  
-   Uma rotina específica do MBCS. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned` **char\***. Por exemplo, `_tcsrev` mapeia para `_mbsrev`, que espera e retorna uma cadeia de caracteres do tipo `unsigned` **char\***. Se você usar o **TCHAR** tipo de dados de texto genérico para seus tipos de cadeia de caracteres, não há um possível conflito de tipo porque **TCHAR** mapeia para o tipo `char`.  
  
 A seguir estão três soluções para evitar esse conflito de tipo (e os avisos do compilador C ou erros do compilador C++ que resultariam):  
  
-   Use o comportamento padrão. TCHAR. h fornece protótipos de rotina de texto genérico para rotinas nas bibliotecas de tempo de execução, como no exemplo a seguir.  
  
    ```  
    char * _tcsrev(char *);  
    ```  
  
     No caso padrão, o protótipo para `_tcsrev` mapeia para `_mbsrev` por meio de uma conversão em Libc.lib. Isso altera os tipos do `_mbsrev` parâmetros de entrada e saída retornam o valor de **TCHAR \***  (ou seja, `char` **\***) para `unsigned` `char` **\***. Esse método garante o tipo correspondente ao usar **TCHAR**, mas é relativamente lenta devido à sobrecarga de chamada de função.  
  
-   Use inlining de função incorporando a seguinte instrução de pré-processador em seu código.  
  
    ```  
    #define _USE_INLINING  
    ```  
  
     Este método faz com que uma conversão de função embutida, fornecido em TCHAR. h para mapear a rotina de texto genérico diretamente para a rotina MBCS apropriada. O seguinte trecho de código de TCHAR. h fornece um exemplo de como isso é feito.  
  
    ```  
    __inline char *_tcsrev(char *_s1)  
    {return (char *)_mbsrev((unsigned char *)_s1);}  
    ```  
  
     Se você pode usar o inlining, essa é a melhor solução, pois ela garante o tipo de correspondência e tem um custo sem tempo adicional.  
  
-   Use o mapeamento direto ao incorporar a seguinte instrução de pré-processador em seu código.  
  
    ```  
    #define _MB_MAP_DIRECT  
    ```  
  
     Essa abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão ou não é possível usar inlining. Faz com que a rotina de texto genérico deve ser mapeado por uma macro diretamente para a versão MBCS da rotina, como no exemplo a seguir do TCHAR. h.  
  
    ```  
    #define _tcschr _mbschr  
    ```  
  
     Quando você usar essa abordagem, você deve ter cuidado para garantir o uso de tipos de dados apropriados para argumentos de cadeia de caracteres e valores de retorno de cadeia de caracteres. Você pode usar a conversão de tipo para garantir a correspondência do tipo correto ou pode usar o tipo de dados de texto genérico **_TXCHAR**. **Txchar** mapeia para o tipo `char` no código SBCS mas mapeia para o tipo `unsigned` `char` no código MBCS. Para obter mais informações sobre as macros de texto genérico, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="see-also"></a>Consulte também  
 [Mapeamentos de texto genéricos em Tchar.h](../text/generic-text-mappings-in-tchar-h.md)