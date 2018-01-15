---
title: Classe SafeInt | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: SafeInt
dev_langs: C++
helpviewer_keywords: SafeInt class
ms.assetid: 27a8f087-2511-46f9-8d76-2aeb66ca272f
caps.latest.revision: "16"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ea076ea092257fd5bf6acd6d597f79ef42dd96f2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="safeint-class"></a>Classe SafeInt
Estende os primitivos de inteiro para ajudar a impedir o estouro de inteiro e permite comparar os diferentes tipos de inteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T, typename E = _SAFEINT_DEFAULT_ERROR_POLICY>  
class SafeInt;  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Modelo|Descrição|  
|--------------|-----------------|  
|T|O tipo de número inteiro ou o parâmetro booliano que `SafeInt` substitui.|  
|E|Um tipo de dados enumerado que define o política de tratamento de erros.|  
|U|O tipo de número inteiro ou um parâmetro booliano para o secundário operando.|  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] rhs|Um parâmetro de entrada que representa o valor à direita do operador em várias funções autônomos.|  
|[in],|Um parâmetro de entrada que representa o valor à direita do operador em várias funções autônomos.|  
|[in] bits|Um parâmetro de entrada que representa o valor à direita do operador em várias funções autônomos.|  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[SafeInt::SafeInt](../windows/safeint-safeint.md)|Construtor padrão.|  
  
### <a name="assignment-operators"></a>Operadores de atribuição  
  
|Nome|Sintaxe|  
|----------|------------|  
|=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator= (const U& rhs)`|  
|=|`SafeInt<T,E>& operator= (const T& rhs) throw()`|  
|=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator= (const SafeInt<U, E>& rhs)`|  
|=|`SafeInt<T,E>& operator= (const SafeInt<T,E>& rhs) throw()`|  
  
### <a name="casting-operators"></a>Operadores de conversão  
  
|Nome|Sintaxe|  
|----------|------------|  
|bool|`operator bool() throw()`|  
|char|`operator char() const`|  
|signed char|`operator signed char() const`|  
|unsigned char|`operator unsigned char() const`|  
|__int16|`operator __int16() const`|  
|unsigned __int16|`operator unsigned __int16() const`|  
|__int32|`operator __int32() const`|  
|unsigned __int32|`operator unsigned __int32() const`|  
|long|`operator long() const`|  
|unsigned long|`operator unsigned long() const`|  
|__int64|`operator __int64() const`|  
|unsigned __int64|`operator unsigned __int64() const`|  
|wchar_t|`operator wchar_t() const`|  
  
### <a name="comparison-operators"></a>Operadores de comparação  
  
|Nome|Sintaxe|  
|----------|------------|  
|<|`template<typename U>`<br /><br /> `bool operator< (U rhs) const throw()`|  
|<|`bool operator< (SafeInt<T,E> rhs) const throw()`|  
|>=|`template<typename U>`<br /><br /> `bool operator>= (U rhs) const throw()`|  
|>=|`Bool operator>= (SafeInt<T,E> rhs) const throw()`|  
|>|`template<typename U>`<br /><br /> `bool operator> (U rhs) const throw()`|  
|>|`Bool operator> (SafeInt<T,E> rhs) const throw()`|  
|<=|`template<typename U>`<br /><br /> `bool operator<= (U rhs) const throw()`|  
|<=|`bool operator<= (SafeInt<T,E> rhs) const throw()`|  
|==|`template<typename U>`<br /><br /> `bool operator== (U rhs) const throw()`|  
|==|`bool operator== (bool rhs) const throw()`|  
|==|`bool operator== (SafeInt<T,E> rhs) const throw()`|  
|!=|`template<typename U>`<br /><br /> `bool operator!= (U rhs) const throw()`|  
|!=|`bool operator!= (bool b) const throw()`|  
|!=|`bool operator!= (SafeInt<T,E> rhs) const throw()`|  
  
### <a name="arithmetic-operators"></a>Operadores aritméticos  
  
|Nome|Sintaxe|  
|----------|------------|  
|+|`const SafeInt<T,E>& operator+ () const throw()`|  
|-|`SafeInt<T,E> operator- () const`|  
|++|`SafeInt<T,E>& operator++ ()`|  
|--|`SafeInt<T,E>& operator-- ()`|  
|%|`template<typename U>`<br /><br /> `SafeInt<T,E> operator% (U rhs) const`|  
|%|`SafeInt<T,E> operator% (SafeInt<T,E> rhs) const`|  
|%=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator%= (U rhs)`|  
|%=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator%= (SafeInt<U, E> rhs)`|  
|*|`template<typename U>`<br /><br /> `SafeInt<T,E> operator* (U rhs) const`|  
|*|`SafeInt<T,E> operator* (SafeInt<T,E> rhs) const`|  
|*=|`SafeInt<T,E>& operator*= (SafeInt<T,E> rhs)`|  
|*=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator*= (U rhs)`|  
|*=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator*= (SafeInt<U, E> rhs)`|  
|/|`template<typename U>`<br /><br /> `SafeInt<T,E> operator/ (U rhs) const`|  
|/|`SafeInt<T,E> operator/ (SafeInt<T,E> rhs ) const`|  
|/=|`SafeInt<T,E>& operator/= (SafeInt<T,E> i)`|  
|/=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator/= (U i)`|  
|/=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator/= (SafeInt<U, E> i)`|  
|+|`SafeInt<T,E> operator+ (SafeInt<T,E> rhs) const`|  
|+|`template<typename U>`<br /><br /> `SafeInt<T,E> operator+ (U rhs) const`|  
|+=|`SafeInt<T,E>& operator+= (SafeInt<T,E> rhs)`|  
|+=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator+= (U rhs)`|  
|+=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator+= (SafeInt<U, E> rhs)`|  
|-|`template<typename U>`<br /><br /> `SafeInt<T,E> operator- (U rhs) const`|  
|-|`SafeInt<T,E> operator- (SafeInt<T,E> rhs) const`|  
|-=|`SafeInt<T,E>& operator-= (SafeInt<T,E> rhs)`|  
|-=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator-= (U rhs)`|  
|-=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator-= (SafeInt<U, E> rhs)`|  
  
### <a name="logical-operators"></a>Operadores Lógicos  
  
|Nome|Sintaxe|  
|----------|------------|  
|!|`bool operator !() const throw()`|  
|~|`SafeInt<T,E> operator~ () const throw()`|  
|<<|`template<typename U>`<br /><br /> `SafeInt<T,E> operator<< (U bits) const throw()`|  
|<<|`template<typename U>`<br /><br /> `SafeInt<T,E> operator<< (SafeInt<U, E> bits) const throw()`|  
|<<=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator<<= (U bits) throw()`|  
|<<=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator<<= (SafeInt<U, E> bits) throw()`|  
|>>|`template<typename U>`<br /><br /> `SafeInt<T,E> operator>> (U bits) const throw()`|  
|>>|`template<typename U>`<br /><br /> `SafeInt<T,E> operator>> (SafeInt<U, E> bits) const throw()`|  
|>>=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator>>= (U bits) throw()`|  
|>>=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator>>= (SafeInt<U, E> bits) throw()`|  
|&|`SafeInt<T,E> operator& (SafeInt<T,E> rhs) const throw()`|  
|&|`template<typename U>`<br /><br /> `SafeInt<T,E> operator& (U rhs) const throw()`|  
|&=|`SafeInt<T,E>& operator&= (SafeInt<T,E> rhs) throw()`|  
|&=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&= (U rhs) throw()`|  
|&=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&= (SafeInt<U, E> rhs) throw()`|  
|^|`SafeInt<T,E> operator^ (SafeInt<T,E> rhs) const throw()`|  
|^|`template<typename U>`<br /><br /> `SafeInt<T,E> operator^ (U rhs) const throw()`|  
|^=|`SafeInt<T,E>& operator^= (SafeInt<T,E> rhs) throw()`|  
|^=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator^= (U rhs) throw()`|  
|^=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator^= (SafeInt<U, E> rhs) throw()`|  
|&#124;|`SafeInt<T,E> operator&#124; (SafeInt<T,E> rhs) const throw()`|  
|&#124;|`template<typename U>`<br /><br /> `SafeInt<T,E> operator&#124; (U rhs) const throw()`|  
|&#124;=|`SafeInt<T,E>& operator&#124;= (SafeInt<T,E> rhs) throw()`|  
|&#124;=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&#124;= (U rhs) throw()`|  
|&#124;=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&#124;= (SafeInt<U, E> rhs) throw()`|  
  
## <a name="remarks"></a>Comentários  
 O `SafeInt` classe protege contra estouro de inteiro em operações matemáticas. Por exemplo, considere a adição de dois inteiros de 8 bits: uma tem um valor de 200 e o segundo tem um valor de 100. A operação matemática correta seria 200 + 100 = 300. No entanto, devido ao limite de número inteiro de 8 bits, o bit superior serão perdido e o compilador retorna 44 (300-2<sup>8</sup>) como o resultado. Qualquer operação que depende da equação matemática irá gerar um comportamento inesperado.  
  
 O `SafeInt` classe verifica se ocorre um estouro aritmético ou se o código tenta fazer uma divisão por zero. Em ambos os casos, a classe chama o manipulador de erro para avisar o programa do problema potencial.  
  
 Essa classe também permite que você compare dois tipos diferentes de inteiros como eles são `SafeInt` objetos. Normalmente, quando você executa uma comparação, primeiro você deve converter os números para ser do mesmo tipo. Converter um número em outro tipo geralmente exige verificações para certificar-se de que não há nenhuma perda de dados.  
  
 A tabela de operadores neste tópico lista os operadores matemáticos e comparação com suporte a `SafeInt` classe. Operadores matemáticos mais retornam um `SafeInt` objeto do tipo `T`.  
  
 Operações de comparação entre um `SafeInt` e um tipo integral pode ser executado em qualquer direção. Por exemplo, `SafeInt<int>(x) < y` e `y > SafeInt<int>(x)` são válidos e retornará o mesmo resultado.  
  
 Muitos operadores binários não dão suporte a diferentes `SafeInt` tipos. Um exemplo disso é o `&` operador. `SafeInt<T, E> & int`há suporte, mas `SafeInt<T, E> & SafeInt<U, E>` não é. No segundo exemplo, o compilador não souber o tipo de parâmetro a retornar. Uma solução para esse problema é converter o segundo parâmetro para o tipo base. Usando os mesmos parâmetros, isso pode ser feito com `SafeInt<T, E> & (U)SafeInt<U, E>`.  
  
> [!NOTE]
>  Para todas as operações bit a bit, os dois parâmetros diferentes devem ter o mesmo tamanho. Se os tamanhos forem diferentes, o compilador gerará um [ASSERT](../mfc/reference/diagnostic-services.md#assert) exceção. Os resultados dessa operação não podem ser garantidos sejam precisos. Para resolver esse problema, converta o parâmetro menor até que ele é o mesmo tamanho que o parâmetro maior.  
  
 Operadores shift, deslocamento de bits maior do que existe para o tipo de modelo lançará uma exceção de declaração. Isso não terá efeito no modo de liberação. Misturar os dois tipos de parâmetros de SafeInt é possível para os operadores shift porque o tipo de retorno é o mesmo que o tipo original. O número à direita do operador só indica o número de bits para deslocar.  
  
 Quando você executa uma comparação lógica com um objeto SafeInt, a comparação é estritamente aritmética. Por exemplo, considere essas expressões:  
  
-   `SafeInt<uint>((uint)~0) > -1`  
  
-   `((uint)~0) > -1`  
  
 A primeira instrução resolve para `true`, mas a segunda instrução resolve para `false`. A negação bit a bit 0 é 0xFFFFFFFF. Na segunda instrução, o operador de comparação padrão compara 0xFFFFFFFF para 0xFFFFFFFF e considera que elas são iguais. O operador de comparação para o `SafeInt` classe percebe que o segundo parâmetro for negativo, enquanto o primeiro parâmetro não está assinado. Portanto, embora a representação de bits é idêntica, o `SafeInt` operador lógico reconhece que o inteiro sem sinal é maior do que -1.  
  
 Tenha cuidado ao usar o `SafeInt` classe junto com o `?:` operador ternário. Considere a seguinte linha de código.  
  
```  
Int x = flag ? SafeInt<unsigned int>(y) : -1;  
```  
  
 O compilador converte para isso:  
  
```  
Int x = flag ? SafeInt<unsigned int>(y) : SafeInt<unsigned int>(-1);  
```  
  
 Se `flag` é `false`, o compilador gera uma exceção em vez de atribuir o valor de -1 para `x`. Portanto, para evitar esse comportamento, o código correto a ser usado é a linha a seguir.  
  
```  
Int x = flag ? (int) SafeInt<unsigned int>(y) : -1;  
```  
  
 `T`e `U` podem ser atribuídos a um tipo booliano, tipo de caractere ou tipo inteiro. O inteiro tipos podem ser assinados ou não assinados e qualquer tamanho de 8 bits para 64 bits.  
  
> [!NOTE]
>  Embora o `SafeInt` classe aceita qualquer tipo de número inteiro, ele executa com mais eficiência com tipos não assinados.  
  
 `E`é o mecanismo de tratamento de erros que `SafeInt` usa. Dois mecanismos de tratamento de erro são fornecidos com a biblioteca de SafeInt. A política padrão é `SafeIntErrorPolicy_SafeIntException`, que gera um [classe SafeIntException](../windows/safeintexception-class.md) exceção quando ocorre um erro. A outra política é `SafeIntErrorPolicy_InvalidParameter`, que interrompe o programa se ocorrer um erro.  
  
 Há duas opções para personalizar a política de erro. A primeira opção é definir o parâmetro `E` quando você cria um `SafeInt`. Use essa opção quando desejar alterar o tratamento de erro política para apenas um `SafeInt`. A outra opção é definir `_SAFEINT_DEFAULT_ERROR_POLICY` seja sua classe personalizada de tratamento de erros antes de incluir o `SafeInt` biblioteca. Use essa opção quando você deseja alterar o política para todas as instâncias de tratamento de erros padrão a `SafeInt` classe em seu código.  
  
> [!NOTE]
>  Uma classe personalizada que manipula erros da biblioteca de SafeInt não deve retornar o controle para o código que chamou o manipulador de erro. Depois que o manipulador de erro é chamado, o resultado da `SafeInt` operação não pode ser confiável.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint.h  
  
 **Namespace:** msl::utilities  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeIntException](../windows/safeintexception-class.md)