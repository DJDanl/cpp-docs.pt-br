---
title: "Classe codecvt | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "codecvt"
  - "std::codecvt"
  - "std.codecvt"
  - "xlocale/std::codecvt"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe codecvt"
ms.assetid: 37d3efa1-2b7f-42b6-b04f-7a972c8c2c86
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe codecvt
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade. Ela pode controlar conversões entre uma sequência de valores usada para codificar caracteres dentro do programa e uma sequência de valores usada para codificar caracteres fora do programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType, class Byte, class StateType>  
class codecvt : public locale::facet, codecvt_base;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
 `Byte`  
 Um tipo usado para codificar caracteres fora de um programa.  
  
 `StateType`  
 Um tipo que pode ser usado para representar estados intermediários de uma conversão entre tipos internos e externos das representações de caractere.  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve um objeto que pode servir como um [faceta de localidade](../standard-library/locale-class.md#facet_class), para controlar conversões entre uma sequência de valores do tipo `CharType` e uma sequência de valores do tipo `Byte`. A classe `StateType` caracteriza a transformação – e um objeto da classe `StateType` armazena todas as informações de estado necessárias durante uma conversão.  
  
 A codificação interna usa uma representação com um número fixo de bytes por caractere, geralmente do tipo `char` ou do tipo `wchar_t`.  
  
 Como qualquer faceta de localidade, a `id` de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em `id`.  
  
 As versões do modelo do [do_in](#codecvt__do_in) e [do_out](#codecvt__do_out) sempre retornará `codecvt_base::noconv`.  
  
 A Biblioteca Padrão do C++ define várias especializações explícitas:  
  
 `template<>`  
  
 `codecvt<wchar_t, char, mbstate_t>`  
  
 conversões entre sequências `wchar_t` e `char`.  
  
 `template<>`  
  
 `codecvt<char16_t, char, mbstate_t>`  
  
 conversões entre sequências `char16_t` codificadas como UTF-16 e sequências `char` codificadas como UTF-8.  
  
 `template<>`  
  
 `codecvt<char32_t, char, mbstate_t>`  
  
 conversões entre sequências `char32_t` codificadas como UTF-32 (UCS-4) e sequências `char` codificadas como UTF-8.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[codecvt](#codecvt__codecvt)|O construtor para objetos da classe `codecvt` que serve como uma faceta de localidade para tratar conversões.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[extern_type](#codecvt__extern_type)|Um tipo de caractere que é usado para representações externas.|  
|[intern_type](#codecvt__intern_type)|Um tipo de caractere que é usado para representações internas.|  
|[state_type](#codecvt__state_type)|Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[always_noconv](#codecvt__always_noconv)|Testa se nenhuma conversão precisa ser feita.|  
|[do_always_noconv](#codecvt__do_always_noconv)|Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.|  
|[do_encoding](#codecvt__do_encoding)|Uma função virtual que testa se a codificação do fluxo `Byte` é dependente de estado, se a taxa entre os `Byte`s usados e os `CharType`s produzidos é constante e, em caso positivo, determina o valor dessa taxa.|  
|[do_in](#codecvt__do_in)|Uma função virtual chamada para converter uma sequência de `Byte`s internos em uma sequência de `CharType`s externos.|  
|[do_length](#codecvt__do_length)|Uma função virtual que determina quantos `Byte`s de uma determinada sequência de `Byte`s externos produzem não mais do que um determinado número de `CharType`s internos e retorna esse número de `Byte`s.|  
|[do_max_length](#codecvt__do_max_length)|Uma função virtual que retorna o número máximo de Bytes externos necessários para gerar um `CharType` interno.|  
|[do_out](#codecvt__do_out)|Uma função virtual chamada para converter uma sequência de `CharType`s internos em uma sequência de Bytes externos.|  
|[do_unshift](#codecvt__do_unshift)|Uma função virtual chamada para fornecer os `Byte`s necessários em uma conversão dependente de estado para completar o último caractere em uma sequência de `Byte`s.|  
|[codificação](#codecvt__encoding)|Testa se a codificação do fluxo `Byte` é dependente de estado, se a taxa entre os `Byte`s usados e os `CharType`s produzidos é constante e, em caso positivo, determina o valor dessa taxa.|  
|[em](#codecvt__in)|Converte uma representação externa de uma sequência de `Byte`s em uma representação interna de uma sequência de `CharType`s.|  
|[comprimento](#codecvt__length)|Determina quantos `Byte`s de uma determinada sequência de `Byte`s externos produzem não mais do que um determinado número de `CharType`s internos e retorna esse número de `Byte`s.|  
|[max_length](#codecvt__max_length)|Retorna o número máximo de `Byte`s externos necessários para gerar um `CharType` interno.|  
|[out](#codecvt__out)|Converte uma sequência de `CharType`s internos em uma sequência de `Byte`s externos.|  
|[unshift](#codecvt__unshift)|Fornece os `Byte`s externos necessários em uma conversão dependente de estado para completar o último caractere da sequência de `Byte`s.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< localidade>  
  
 **Namespace:** std  
  
##  <a name="a-namecodecvtalwaysnoconva-codecvtalwaysnoconv"></a><a name="codecvt__always_noconv"></a>  codecvt:: always_noconv  
 Testa se nenhuma conversão precisa ser feita.  
  
```  
bool always_noconv() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que é **true** se nenhuma conversão precisa ser feita; **False** é pelo menos um precisa ser feito.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de membro [do_always_noconv](#codecvt__do_always_noconv).  
  
### <a name="example"></a>Exemplo  
  
```  
// codecvt_always_noconv.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
using namespace std;  
  
int main( )     
{  
   locale loc ( "German_Germany" );  
   bool result1 = use_facet<codecvt<char, char, mbstate_t> >   
      ( loc ).always_noconv( );  
  
   if ( result1 )  
      cout << "No conversion is needed." << endl;  
   else  
      cout << "At least one conversion is required." << endl;  
  
   bool result2 = use_facet<codecvt<wchar_t, char, mbstate_t> >   
      ( loc ).always_noconv( );  
  
   if ( result2 )  
      cout << "No conversion is needed." << endl;  
   else  
      cout << "At least one conversion is required." << endl;  
}  
```  
  
```Output  
No conversion is needed.  
At least one conversion is required.  
```  
  
##  <a name="a-namecodecvtcodecvta-codecvtcodecvt"></a><a name="codecvt__codecvt"></a>  codecvt:: codecvt  
 O construtor para objetos da classe codecvt que serve como uma faceta de localidade para tratar conversões.  
  
```  
explicit codecvt(size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória para o objeto.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para a `_Refs` e seus significados são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que contêm-lo.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \> 0: esses valores não são definidos.  
  
 O construtor inicializa sua `locale::facet` objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)( `_Refs`) *.*  
  
##  <a name="a-namecodecvtdoalwaysnoconva-codecvtdoalwaysnoconv"></a><a name="codecvt__do_always_noconv"></a>  codecvt:: do_always_noconv  
 Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.  
  
```  
virtual bool do_always_noconv() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A função de membro virtual protegida retorna **true** somente se todas as chamadas para [do_in](#codecvt__do_in) ou [do_out](#codecvt__do_out) retorna **noconv**.  
  
 A versão do modelo sempre retorna **true**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [always_noconv](#codecvt__always_noconv), que chama `do_always_noconv`.  
  
##  <a name="a-namecodecvtdoencodinga-codecvtdoencoding"></a><a name="codecvt__do_encoding"></a>  codecvt:: do_encoding  
 Uma função virtual que testa se a codificação da **bytes** fluxo é dependente de estado, se a proporção entre a **bytes**s usados e o **CharType**s produzidos é constante e, em caso afirmativo, determina o valor dessa taxa.  
  
```  
virtual int do_encoding() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de membro virtual protegida:  
  
-   – 1, se a codificação de sequências do tipo `extern_type` é dependente do estado.  
  
-   0, se a codificação envolve sequências de comprimentos variáveis.  
  
- *N*, se a codificação envolve somente sequências de comprimento *N*  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [codificação](#codecvt__encoding), que chama `do_encoding`.  
  
##  <a name="a-namecodecvtdoina-codecvtdoin"></a><a name="codecvt__do_in"></a>  codecvt:: do_in  
 Uma função virtual chamada para converter uma sequência de externos **bytes**s em uma sequência de interno **CharType**s.  
  
```  
virtual result do_in(
    StateType& _State,  
    const Byte* first1,   
    const Byte* last1,   
    const Byte*& next1,  
    CharType* first2,  
    CharType* last2,  
    CharType*& next2,) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first1`  
 Ponteiro para o início da sequência a ser convertido.  
  
 ` last1`  
 Ponteiro para o final da sequência a ser convertido.  
  
 ` next1`  
 Ponteiro além do fim da sequência de convertido para o primeiro caractere não convertido.  
  
 ` first2`  
 Ponteiro para o início da sequência convertido.  
  
 ` last2`  
 Ponteiro para o final da sequência convertido.  
  
 ` next2`  
 Ponteiro para o **CharType** que vem após o último convertida **CharType**, para o primeiro caractere inalterado na sequência de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Um retorno que indica o êxito parcial ou êxito, falha da operação. A função retorna:  
  
- **codecvt_base::error** se a sequência de origem estiver doente formado.  
  
- `codecvt_base::noconv` Se a função não realiza nenhuma conversão.  
  
- **codecvt_base::OK** se a conversão for bem-sucedida.  
  
- **codecvt_base::Partial** se a fonte for insuficiente ou se o destino não é grande o suficiente, para que a conversão seja bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 `_State` deve representar o estado inicial de conversão no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado está especificado.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [em](#codecvt__in), que chama `do_in`.  
  
##  <a name="a-namecodecvtdolengtha-codecvtdolength"></a><a name="codecvt__do_length"></a>  codecvt:: do_length  
 Uma função virtual determina quantos **bytes**s de uma determinada sequência externa **bytes**s produzem não mais do que um determinado número de interno **CharType**s e retorna o número de **bytes**s.  
  
```  
virtual int do_length(
    const StateType& _State,  
    const Byte* first1,   
    const Byte* last1,  
    size_t _Len2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first1`  
 Ponteiro para o início da sequência externo.  
  
 ` last1`  
 Ponteiro para o final da sequência externo.  
  
 `_Len2`  
 O número máximo de **bytes**que pode ser retornado pela função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que representa uma contagem do número máximo de conversões, não é maiores que `_Len2`, definido pela sequência de origem externa em [ ` first1`, ` last1`).  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida efetivamente chama `do_in`( `_State`, ` first1`, ` last1`, ` next1`, `_Buf`, `_Buf` + `_Len2`, ` next2`) para `_State` (uma cópia do estado), algum buffer `_Buf`, ponteiros e ` next1`e ` next2`.  
  
 Ele então retorna ` next2` – **buf**. Portanto, ele conta o número máximo de conversões, não é maiores que `_Len2`, definido pela sequência de origem em [ ` first1`, ` last1`).  
  
 A versão do modelo sempre retorna o menor dos ` last1` – ` first1` e `_Len2`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [comprimento](#codecvt__length), que chama **do_length**.  
  
##  <a name="a-namecodecvtdomaxlengtha-codecvtdomaxlength"></a><a name="codecvt__do_max_length"></a>  codecvt:: do_max_length  
 Uma função virtual que retorna o número máximo de externos **bytes**s necessários para gerar um interno **CharType**.  
  
```  
virtual int do_max_length() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de **bytes**s necessários para gerar um **CharType**.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida retorna o maior valor permitido que pode ser retornado por [do_length](#codecvt__do_length)( ` first1`, ` last1`, 1) para obter valores válidos arbitrários de ` first1` e ` last1`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [max_length](#codecvt__max_length), que chama `do_max_length`.  
  
##  <a name="a-namecodecvtdoouta-codecvtdoout"></a><a name="codecvt__do_out"></a>  codecvt:: do_out  
 Uma função virtual chamada para converter uma sequência de interno **CharType**s em uma sequência de externo **bytes**s.  
  
```  
virtual result do_out(
    StateType& _State,  
    const CharType* first1,   
    const CharType* last1,  
    const CharType*& next1,  
    Byte* first2,   
    Byte* last2,   
    Byte*& next2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first1`  
 Ponteiro para o início da sequência a ser convertido.  
  
 ` last1`  
 Ponteiro para o final da sequência a ser convertido.  
  
 ` next1`  
 Referência a um ponteiro para o primeiro não convertidos **CharType**, depois da última **CharType** convertido.  
  
 ` first2`  
 Ponteiro para o início da sequência convertido.  
  
 ` last2`  
 Ponteiro para o final da sequência convertido.  
  
 ` next2`  
 Referência a um ponteiro para o primeiro não convertidos **bytes**, depois da última **bytes** convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna:  
  
- **codecvt_base::error** se a sequência de origem estiver doente formado.  
  
- `codecvt_base::noconv` Se a função não realiza nenhuma conversão.  
  
- **codecvt_base::OK** se a conversão for bem-sucedida.  
  
- **codecvt_base::Partial** se a fonte for insuficiente ou se o destino não é grande o suficiente para que a conversão seja bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 `_State` deve representar o estado inicial de conversão no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado está especificado.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [out](#codecvt__out), que chama `do_out`.  
  
##  <a name="a-namecodecvtdounshifta-codecvtdounshift"></a><a name="codecvt__do_unshift"></a>  codecvt:: do_unshift  
 Uma função virtual chamada para fornecer a **bytes**s necessários em uma conversão dependente de estado para completar o último caractere em uma sequência de **bytes**s.  
  
```  
virtual result do_unshift(
    StateType& _State,  
    Byte* first2,   
    Byte* last2,   
    Byte*& next2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first2`  
 Ponteiro para a primeira posição no intervalo de destino.  
  
 ` last2`  
 Ponteiro para a última posição no intervalo de destino.  
  
 ` next2`  
 Ponteiro para o primeiro elemento inalterado na sequência de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna:  
  
- **codecvt_base::error** se _ *estado* representa um estado inválido  
  
- `codecvt_base::noconv` Se a função não realiza nenhuma conversão  
  
- **codecvt_base::OK** se a conversão for bem-sucedida  
  
- **codecvt_base::Partial** se o destino não é grande o suficiente para que a conversão seja bem-sucedida  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida tenta converter o elemento de origem **CharType**(0) para uma sequência de destino que ele armazena no [ ` first2`, ` last2`), exceto para o elemento de finalização **bytes**(0). Ele sempre armazena em ` next2` um ponteiro para o primeiro elemento inalterado na sequência de destino.  
  
 _ *Estado* deve representar o estado inicial de conversão no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Normalmente, converter o elemento de origem **CharType**(0) deixa o estado atual no estado inicial de conversão.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [unshift](#codecvt__unshift), que chama `do_unshift`.  
  
##  <a name="a-namecodecvtencodinga-codecvtencoding"></a><a name="codecvt__encoding"></a>  codecvt:: Encoding  
 Testa se a codificação da **bytes** fluxo é dependente de estado, se a proporção entre a **bytes**s usados e o **CharType**s produzidos é constante e, em caso afirmativo, determina o valor dessa taxa.  
  
```  
int encoding() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno for positivo, esse valor é o número constante de **bytes** caracteres necessários para produzir o **CharType** caracteres.  
  
 Retorna a função de membro virtual protegida:  
  
-   – 1, se a codificação de sequências do tipo `extern_type` é dependente do estado.  
  
-   0, se a codificação envolve sequências de comprimentos variáveis.  
  
- *N*, se a codificação envolve somente sequências de comprimento *s.*  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de membro [do_encoding](#codecvt__do_encoding).  
  
### <a name="example"></a>Exemplo  
  
```  
// codecvt_encoding.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
using namespace std;  
  
int main( )     
{  
   locale loc ( "German_Germany" );  
   int result1 = use_facet<codecvt<char, char, mbstate_t> > ( loc ).encoding ( );  
   cout << result1 << endl;  
   result1 = use_facet<codecvt<wchar_t, char, mbstate_t> > ( loc ).encoding( );  
   cout << result1 << endl;  
   result1 = use_facet<codecvt<char, wchar_t, mbstate_t> > ( loc ).encoding( );  
   cout << result1 << endl;  
}  
```  
  
```Output  
1  
1  
1  
```  
  
##  <a name="a-namecodecvtexterntypea-codecvtexterntype"></a><a name="codecvt__extern_type"></a>  codecvt:: extern_type  
 Um tipo de caractere que é usado para representações externas.  
  
```  
typedef Byte extern_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **bytes**.  
  
##  <a name="a-namecodecvtina-codecvtin"></a><a name="codecvt__in"></a>  codecvt:: in  
 Converte uma representação externa de uma sequência de **bytes**s para uma representação interna de uma sequência de **CharType**s.  
  
```  
result in(
    StateType& _State,  
    const Byte* first1,   
    const Byte* last1,   
    const Byte*& next1,  
    CharType* first2,  
    CharType* last2,  
    CharType*& next2,) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first1`  
 Ponteiro para o início da sequência a ser convertido.  
  
 ` last1`  
 Ponteiro para o final da sequência a ser convertido.  
  
 ` next1`  
 Ponteiro além do fim da sequência convertido para o primeiro caractere não convertido.  
  
 ` first2`  
 Ponteiro para o início da sequência convertido.  
  
 ` last2`  
 Ponteiro para o final da sequência convertido.  
  
 ` next2`  
 Ponteiro para o **CharType** que vem após o último convertida **Chartype** para o primeiro caractere inalterado na sequência de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Um retorno que indica o sucesso, êxito parcial ou falha da operação. A função retorna:  
  
- **codecvt_base::error** se a sequência de origem estiver doente formado.  
  
- `codecvt_base::noconv` Se a função não realiza nenhuma conversão.  
  
- **codecvt_base::OK** se a conversão for bem-sucedida.  
  
- **codecvt_base::Partial** se a fonte for insuficiente ou se o destino não é grande o suficiente para que a conversão seja bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 `_State` deve representar o estado inicial de conversão no início de uma nova sequência de origem. A função altera o valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Depois de uma conversão parcial, `_State` deve ser definido para permitir a conversão retomar a chegada de novos caracteres.  
  
 Retorna a função de membro [do_in](#codecvt__do_in)( `_State`, _ *First1, last1, next1, First2, _Llast2, next2*).  
  
### <a name="example"></a>Exemplo  
  
```  
// codecvt_in.cpp  
// compile with: /EHsc  
#define _INTL  
#include <locale>  
#include <iostream>  
using namespace std;  
#define LEN 90  
int main( )     
{  
   char* pszExt = "This is the string to be converted!";  
   wchar_t pwszInt [LEN+1];  
   memset(&pwszInt[0], 0, (sizeof(wchar_t))*(LEN+1));  
   const char* pszNext;  
   wchar_t* pwszNext;  
   mbstate_t state = {0};  
   locale loc("C");//English_Britain");//German_Germany  
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >  
     ( loc ).in( state,  
          pszExt, &pszExt[strlen(pszExt)], pszNext,  
          pwszInt, &pwszInt[strlen(pszExt)], pwszNext );  
   pwszInt[strlen(pszExt)] = 0;  
   wcout << ( (res!=codecvt_base::error)  L"It worked! " : L"It didn't work! " )  
   << L"The converted string is:\n ["  
   << &pwszInt[0]  
   << L"]" << endl;  
   exit(-1);  
}  
```  
  
```Output  
It worked! The converted string is:  
 [This is the string to be converted!]  
```  
  
##  <a name="a-namecodecvtinterntypea-codecvtinterntype"></a><a name="codecvt__intern_type"></a>  codecvt:: intern_type  
 Um tipo de caractere que é usado para representações internas.  
  
```  
typedef CharType intern_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **CharType**.  
  
##  <a name="a-namecodecvtlengtha-codecvtlength"></a><a name="codecvt__length"></a>  codecvt:: Length  
 Determina quantas **bytes**s de uma determinada sequência externa **bytes**s produzem não mais do que um determinado número de interno **CharType**s e retorna o número de **bytes**s.  
  
```  
int length(
    const StateType& _State,  
    const Byte* first1,   
    const Byte* last1,  
    size_t _Len2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first1`  
 Ponteiro para o início da sequência externo.  
  
 ` last1`  
 Ponteiro para o final da sequência externo.  
  
 `_Len2`  
 O número máximo de Bytes que pode ser retornado pela função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que representa uma contagem do número máximo de conversões, não é maiores que `_Len2`, definido pela sequência de origem externa em [ ` first1`, ` last1`).  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de membro [do_length](#codecvt__do_length)( *_State, first1*, ` last1`, `_Len2`).  
  
### <a name="example"></a>Exemplo  
  
```  
// codecvt_length.cpp  
// compile with: /EHsc  
#define _INTL  
#include <locale>  
#include <iostream>  
using namespace std;  
#define LEN 90  
int main( )     
{  
   char* pszExt = "This is the string whose length is to be measured!";  
   mbstate_t state = {0};  
   locale loc("C");//English_Britain");//German_Germany  
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >  
     ( loc ).length( state,  
          pszExt, &pszExt[strlen(pszExt)], LEN );  
   cout << "The length of the string is: ";  
   wcout << res;  
   cout << "." << endl;  
   exit(-1);  
}  
```  
  
```Output  
The length of the string is: 50.  
```  
  
##  <a name="a-namecodecvtmaxlengtha-codecvtmaxlength"></a><a name="codecvt__max_length"></a>  codecvt:: max_length  
 Retorna o número máximo de externos **bytes**s necessários para gerar um interno **CharType**.  
  
```  
int max_length() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de **bytes**s necessários para gerar um **CharType**.  
  
### <a name="remarks"></a>Comentários  
 Retorna a função de membro [do_max_length](#codecvt__do_max_length).  
  
### <a name="example"></a>Exemplo  
  
```  
// codecvt_max_length.cpp  
// compile with: /EHsc  
#define _INTL  
#include <locale>  
#include <iostream>  
using namespace std;  
  
int main( )     
{  
   locale loc( "C");//English_Britain" );//German_Germany  
   int res = use_facet<codecvt<char, char, mbstate_t> >  
     ( loc ).max_length( );  
   wcout << res << endl;  
}  
```  
  
```Output  
1  
```  
  
##  <a name="a-namecodecvtouta-codecvtout"></a><a name="codecvt__out"></a>  codecvt:: out  
 Converte uma sequência de interno **CharType**s em uma sequência de externo **bytes**s.  
  
```  
result out(
    StateType& _State,  
    const CharType* first1,   
    const CharType* last1,  
    const CharType*& next1,  
    Byte* first2,   
    Byte* last2,   
    Byte*& next2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first1`  
 Ponteiro para o início da sequência a ser convertido.  
  
 ` last1`  
 Ponteiro para o final da sequência a ser convertido.  
  
 ` next1`  
 Referência a um ponteiro para o primeiro não convertidos **CharType** depois da última **CharType** convertido.  
  
 ` first2`  
 Ponteiro para o início da sequência convertido.  
  
 ` last2`  
 Ponteiro para o final da sequência convertido.  
  
 ` next2`  
 Referência a um ponteiro para o primeiro não convertidos **bytes** após o último convertida **bytes**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de membro [do_out](#codecvt__do_out)( `_State`, ` first1`, ` last1`, ` next1`, ` first2`, ` last2`, ` next2`).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [codecvt:: do_out](#codecvt__do_out).  
  
### <a name="example"></a>Exemplo  
  
```  
// codecvt_out.cpp  
// compile with: /EHsc  
#define _INTL  
#include <locale>  
#include <iostream>  
#include <wchar.h>  
using namespace std;  
#define LEN 90  
int main( )     
{  
   char pszExt[LEN+1];  
   wchar_t *pwszInt = L"This is the wchar_t string to be converted.";  
   memset( &pszExt[0], 0, ( sizeof( char ) )*( LEN+1 ) );  
   char* pszNext;  
   const wchar_t* pwszNext;  
   mbstate_t state;  
   locale loc("C");//English_Britain");//German_Germany  
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >  
      ( loc ).out( state,  
      pwszInt, &pwszInt[wcslen( pwszInt )], pwszNext ,  
      pszExt, &pszExt[wcslen( pwszInt )], pszNext );  
   pszExt[wcslen( pwszInt )] = 0;  
   cout << ( ( res!=codecvt_base::error )  "It worked: " : "It didn't work: " )  
   << "The converted string is:\n ["  
   << &pszExt[0]  
   << "]" << endl;  
}  
```  
  
```Output  
It worked: The converted string is:  
 [This is the wchar_t string to be converted.]  
```  
  
##  <a name="a-namecodecvtstatetypea-codecvtstatetype"></a><a name="codecvt__state_type"></a>  codecvt:: state_type  
 Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.  
  
```  
typedef StateType state_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **StateType**.  
  
##  <a name="a-namecodecvtunshifta-codecvtunshift"></a><a name="codecvt__unshift"></a>  codecvt:: unshift  
 Fornece o **bytes**s necessários em uma conversão dependente de estado para completar o último caractere em uma sequência de **bytes**s.  
  
```  
result unshift(
    StateType& _State,  
    Byte* first2,   
    Byte* last2,   
    Byte*& next2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_State`  
 O estado de conversão que é mantido entre as chamadas para a função de membro.  
  
 ` first2`  
 Ponteiro para a primeira posição no intervalo de destino.  
  
 ` last2`  
 Ponteiro para a última posição no intervalo de destino.  
  
 ` next2`  
 Ponteiro para o primeiro elemento inalterado na sequência de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna:  
  
- **codecvt_base::error** se estado representa um estado inválido.  
  
- `codecvt_base::noconv` Se a função não realiza nenhuma conversão.  
  
- **codecvt_base::OK** se a conversão for bem-sucedida.  
  
- **codecvt_base::Partial** se o destino não é grande o suficiente para que a conversão seja bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida tenta converter o elemento de origem **CharType**(0) para uma sequência de destino que ele armazena no [ ` first2`, ` last2`), exceto para o elemento de finalização **bytes**(0). Ele sempre armazena em ` next2` um ponteiro para o primeiro elemento inalterado na sequência de destino.  
  
 `_State` deve representar o estado inicial de conversão no início de uma nova sequência de origem. A função altera o valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Normalmente, converter o elemento de origem **CharType**(0) deixa o estado atual no estado inicial de conversão.  
  
 Retorna a função de membro [do_unshift](#codecvt__do_unshift)( `_State`, ` first2`, ` last2`, ` next2` ).  
  
## <a name="see-also"></a>Consulte também  
 [\< localidade>](../standard-library/locale.md)   
 [Páginas de código](../c-runtime-library/code-pages.md)   
 [Nomes de localidades, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

