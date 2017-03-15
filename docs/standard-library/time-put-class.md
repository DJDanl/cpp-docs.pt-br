---
title: Classe time_put | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::time_put
- time_put
- xloctime/std::time_put
- std.time_put
dev_langs:
- C++
helpviewer_keywords:
- time_put class
ms.assetid: df79493e-3331-48d2-97c3-ac3a745f0791
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8a58639cc0a599f65f2ac8c0073b136a4e969484
ms.lasthandoff: 02/25/2017

---
# <a name="timeput-class"></a>Classe time_put
A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores de tempo em sequências do tipo `CharType`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType,  
    class OutputIterator = ostreambuf_iterator<CharType>>  
class time_put : public locale::facet;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
 `OutputIterator`  
 O tipo de iterador no qual as funções put de tempo gravam sua saída.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[time_put](#time_put__time_put)|O construtor para objetos do tipo `time_put`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#time_put__char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter_type](#time_put__iter_type)|Um tipo que descreve um iterador de saída.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[do_put](#time_put__do_put)|Uma função virtual que gera informações de hora e data como uma sequência de `CharType`s.|  
|[put](#time_put__put)|Gera informações de hora e data como uma sequência de `CharType`s.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
##  <a name="a-nametimeputchartypea--timeputchartype"></a><a name="time_put__char_type"></a>  time_put::char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
##  <a name="a-nametimeputdoputa--timeputdoput"></a><a name="time_put__do_put"></a>  time_put::do_put  
 Uma função virtual que gera informações de hora e data como uma sequência de **CharType**s.  
  
```  
virtual iter_type do_put(
    iter_type next,   
    ios_base& _Iosbase,  
    const tm* _Pt,   
    char _Fmt,   
    char _Mod = 0) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` next`  
 Um iterador de saída no qual a sequência de caracteres que representa a data e hora deve ser inserida.  
  
 `_Iosbase`  
 Não utilizado.  
  
 `_Pt`  
 As informações de data e hora que estão sendo geradas.  
  
 `_Fmt`  
 O formato da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.  
  
 `_Mod`  
 Um modificador do formato. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para a primeira posição após o último elemento inserido.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida gera elementos sequenciais começando em ` next` de valores de hora armazenados no objeto \* `_Pt`, do tipo **tm**. A função retorna um iterador que designa o próximo local a inserir um elemento após a saída gerada.  
  
 A saída é gerada pelas mesmas regras usadas por `strftime`, com um último argumento `_Pt`, para gerar uma série de elementos `char` em uma matriz. Cada elemento `char` é considerado mapeado para um elemento equivalente do tipo **CharType** por um mapeamento um para um simples. Se `_Mod` for igual a zero, o formato efetivo será “%F”, em que F é substituído por `_Fmt`. Caso contrário, o formato efetivo será “%MF”, em que M é substituído por `_Mod`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [put](#time_put__put), que chama `do_put`.  
  
##  <a name="a-nametimeputitertypea--timeputitertype"></a><a name="time_put__iter_type"></a>  time_put::iter_type  
 Um tipo que descreve um iterador de saída.  
  
```  
typedef OutputIterator iter_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **OutputIterator**.  
  
##  <a name="a-nametimeputputa--timeputput"></a><a name="time_put__put"></a>  time_put::put  
 Gera informações de data e hora como uma sequência de **CharType**s.  
  
```  
iter_type put(iter_type next,
    ios_base& _Iosbase,
    char_type _Fill,
    const tm* _Pt,
    char _Fmt,
    char _Mod = 0) const;

iter_type put(iter_type next,
    ios_base& _Iosbase,
    char_type _Fill,
    const tm* _Pt,
    const CharType* first,
    const CharType* last) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` next`  
 Um iterador de saída no qual a sequência de caracteres que representa a data e hora deve ser inserida.  
  
 `_Iosbase`  
 Não utilizado.  
  
 `_Fill`  
 O caractere do tipo **CharType** usado para espaçamento.  
  
 `_Pt`  
 As informações de data e hora que estão sendo geradas.  
  
 `_Fmt`  
 O formato da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.  
  
 `_Mod`  
 Um modificador do formato. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.  
  
 ` first`  
 O início da cadeia de caracteres de formatação da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.  
  
 ` last`  
 O final da cadeia de caracteres de formatação da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para a primeira posição após o último elemento inserido.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna [do_put](#time_put__do_put)( ` next`, `_Iosbase`, `_Fill`, `_Pt`, `_Fmt`, `_Mod`). A segunda função membro copia para \* ` next` ++ qualquer elemento no intervalo [` first`, ` last`] que não seja um percentual (%). Para um percentual seguido por um caractere *C* no intervalo [` first`, ` last`], a função avaliará ` next` = `do_put`( ` next`, `_Iosbase`, `_Fill`, `_Pt`, *C*, 0) e ignorará após *C*. Se, no entanto, *C* for um caractere qualificador do EOQ# definido, seguido por um caractere `C2` no intervalo [` first`, ` last`], a função avaliará ` next` = `do_put`( ` next`, `_Iosbase`, `_Fill`, `_Pt`, `C2`, *C*) e ignorará após `C2`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// time_put_put.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
#include <time.h>  
using namespace std;  
int main( )  
{  
   locale loc;  
   basic_stringstream<char> pszPutI;  
   ios_base::iostate st = 0;  
   struct tm t;  
   memset( &t, 0, sizeof( struct tm ) );  
  
   t.tm_hour = 5;  
   t.tm_min = 30;  
   t.tm_sec = 40;  
   t.tm_year = 00;  
   t.tm_mday = 4;  
   t.tm_mon = 6;  
  
   pszPutI.imbue( loc );  
   char *pattern = "x: %X %x";  
   use_facet <time_put <char> >  
   (loc).put(basic_ostream<char>::_Iter(pszPutI.rdbuf( )),  
          pszPutI, ' ', &t, pattern, pattern+strlen(pattern));  
  
      cout << "num_put( ) = " << pszPutI.rdbuf( )->str( ) << endl;  
  
      char strftimebuf[255];  
      strftime(&strftimebuf[0], 255, pattern, &t);  
      cout << "strftime( ) = " << &strftimebuf[0] << endl;  
}  
```  
  
```Output  
num_put( ) = x: 05:30:40 07/04/00  
strftime( ) = x: 05:30:40 07/04/00  
```  
  
##  <a name="a-nametimeputtimeputa--timeputtimeput"></a><a name="time_put__time_put"></a>  time_put::time_put  
 Construtor para objetos do tipo `time_put`.  
  
```  
explicit time_put(size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para o parâmetro `_Refs` e sua significância são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \> 0: esses valores não estão definidos.  
  
 O construtor inicializa seu objeto base com [locale::facet](../standard-library/locale-class.md#facet_class)( **_***Refs*).  
  
## <a name="see-also"></a>Consulte também  
 [\<locale>](../standard-library/locale.md)   
 [Classe time_base](../standard-library/time-base-class.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


