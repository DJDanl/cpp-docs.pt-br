---
title: "Classe SafeInt | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "SafeInt"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SafeInt"
ms.assetid: 27a8f087-2511-46f9-8d76-2aeb66ca272f
caps.latest.revision: 16
caps.handback.revision: 16
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Classe SafeInt
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Estende as primitivas de inteiro para ajudar a evitar estouro de inteiro e permite comparar tipos diferentes de inteiros.  
  
## Sintaxe  
  
```  
template<typename T, typename E = _SAFEINT_DEFAULT_ERROR_POLICY>  
class SafeInt;  
```  
  
#### Parâmetros  
  
|Modelo|Descrição|  
|------------|---------------|  
|T|O tipo de inteiro ou de parâmetro booliano que `SafeInt` substitui.|  
|E|Um tipo enumerado de dados que define a política de tratamento de erros.|  
|U|O tipo de inteiro ou de parâmetro booliano para o operando secundário.|  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\] rhs|Um parâmetro de entrada que representa o valor à direita do operador em várias funções autônomas.|  
|\[in\] i|Um parâmetro de entrada que representa o valor à direita do operador em várias funções autônomas.|  
|\[in\] bit|Um parâmetro de entrada que representa o valor à direita do operador em várias funções autônomas.|  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[SafeInt::SafeInt](../windows/safeint-safeint.md)|Construtor padrão.|  
  
### Operadores de Atribuição  
  
|Nome|Sintaxe|  
|----------|-------------|  
|\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator= (const U& rhs)`|  
|\=|`SafeInt<T,E>& operator= (const T& rhs) throw()`|  
|\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator= (const SafeInt<U, E>& rhs)`|  
|\=|`SafeInt<T,E>& operator= (const SafeInt<T,E>& rhs) throw()`|  
  
### Operadores de conversão  
  
|Nome|Sintaxe|  
|----------|-------------|  
|bool|`operator bool() throw()`|  
|char|`operator char() const`|  
|gráfico assinado|`operator signed char() const`|  
|gráfico não assinado|`operator unsigned char() const`|  
|\_\_int16|`operator __int16() const`|  
|\_\_int16 sem sinal|`operator unsigned __int16() const`|  
|\_\_int32|`operator __int32() const`|  
|\_\_int32 sinal|`operator unsigned __int32() const`|  
|long|`operator long() const`|  
|unsigned long|`operator unsigned long() const`|  
|\_\_int64|`operator __int64() const`|  
|unsigned \_\_int64|`operator unsigned __int64() const`|  
|wchar\_t|`operator wchar_t() const`|  
  
### Operadores de comparação  
  
|Nome|Sintaxe|  
|----------|-------------|  
|\<|`template<typename U>`<br /><br /> `bool operator< (U rhs) const throw()`|  
|\<|`bool operator< (SafeInt<T,E> rhs) const throw()`|  
|\>\=|`template<typename U>`<br /><br /> `bool operator>= (U rhs) const throw()`|  
|\>\=|`Bool operator>= (SafeInt<T,E> rhs) const throw()`|  
|\>|`template<typename U>`<br /><br /> `bool operator> (U rhs) const throw()`|  
|\>|`Bool operator> (SafeInt<T,E> rhs) const throw()`|  
|\<\=|`template<typename U>`<br /><br /> `bool operator<= (U rhs) const throw()`|  
|\<\=|`bool operator<= (SafeInt<T,E> rhs) const throw()`|  
|\=\=|`template<typename U>`<br /><br /> `bool operator== (U rhs) const throw()`|  
|\=\=|`bool operator== (bool rhs) const throw()`|  
|\=\=|`bool operator== (SafeInt<T,E> rhs) const throw()`|  
|\!\=|`template<typename U>`<br /><br /> `bool operator!= (U rhs) const throw()`|  
|\!\=|`bool operator!= (bool b) const throw()`|  
|\!\=|`bool operator!= (SafeInt<T,E> rhs) const throw()`|  
  
### Operadores aritméticos  
  
|Nome|Sintaxe|  
|----------|-------------|  
|\+|`const SafeInt<T,E>& operator+ () const throw()`|  
|\-|`SafeInt<T,E> operator- () const`|  
|\+\+|`SafeInt<T,E>& operator++ ()`|  
|\-\-|`SafeInt<T,E>& operator-- ()`|  
|%|`template<typename U>`<br /><br /> `SafeInt<T,E> operator% (U rhs) const`|  
|%|`SafeInt<T,E> operator% (SafeInt<T,E> rhs) const`|  
|%\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator%= (U rhs)`|  
|%\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator%= (SafeInt<U, E> rhs)`|  
|\*|`template<typename U>`<br /><br /> `SafeInt<T,E> operator* (U rhs) const`|  
|\*|`SafeInt<T,E> operator* (SafeInt<T,E> rhs) const`|  
|\*\=|`SafeInt<T,E>& operator*= (SafeInt<T,E> rhs)`|  
|\*\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator*= (U rhs)`|  
|\*\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator*= (SafeInt<U, E> rhs)`|  
|\/|`template<typename U>`<br /><br /> `SafeInt<T,E> operator/ (U rhs) const`|  
|\/|`SafeInt<T,E> operator/ (SafeInt<T,E> rhs ) const`|  
|\/\=|`SafeInt<T,E>& operator/= (SafeInt<T,E> i)`|  
|\/\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator/= (U i)`|  
|\/\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator/= (SafeInt<U, E> i)`|  
|\+|`SafeInt<T,E> operator+ (SafeInt<T,E> rhs) const`|  
|\+|`template<typename U>`<br /><br /> `SafeInt<T,E> operator+ (U rhs) const`|  
|\+\=|`SafeInt<T,E>& operator+= (SafeInt<T,E> rhs)`|  
|\+\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator+= (U rhs)`|  
|\+\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator+= (SafeInt<U, E> rhs)`|  
|\-|`template<typename U>`<br /><br /> `SafeInt<T,E> operator- (U rhs) const`|  
|\-|`SafeInt<T,E> operator- (SafeInt<T,E> rhs) const`|  
|\-\=|`SafeInt<T,E>& operator-= (SafeInt<T,E> rhs)`|  
|\-\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator-= (U rhs)`|  
|\-\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator-= (SafeInt<U, E> rhs)`|  
  
### Operadores Lógicos  
  
|Nome|Sintaxe|  
|----------|-------------|  
|\!|`bool operator !() const throw()`|  
|~|`SafeInt<T,E> operator~ () const throw()`|  
|\<\<|`template<typename U>`<br /><br /> `SafeInt<T,E> operator<< (U bits) const throw()`|  
|\<\<|`template<typename U>`<br /><br /> `SafeInt<T,E> operator<< (SafeInt<U, E> bits) const throw()`|  
|\<\<\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator<<= (U bits) throw()`|  
|\<\<\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator<<= (SafeInt<U, E> bits) throw()`|  
|\>\>|`template<typename U>`<br /><br /> `SafeInt<T,E> operator>> (U bits) const throw()`|  
|\>\>|`template<typename U>`<br /><br /> `SafeInt<T,E> operator>> (SafeInt<U, E> bits) const throw()`|  
|\>\>\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator>>= (U bits) throw()`|  
|\>\>\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator>>= (SafeInt<U, E> bits) throw()`|  
|&|`SafeInt<T,E> operator& (SafeInt<T,E> rhs) const throw()`|  
|&|`template<typename U>`<br /><br /> `SafeInt<T,E> operator& (U rhs) const throw()`|  
|&\=|`SafeInt<T,E>& operator&= (SafeInt<T,E> rhs) throw()`|  
|&\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&= (U rhs) throw()`|  
|&\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&= (SafeInt<U, E> rhs) throw()`|  
|^|`SafeInt<T,E> operator^ (SafeInt<T,E> rhs) const throw()`|  
|^|`template<typename U>`<br /><br /> `SafeInt<T,E> operator^ (U rhs) const throw()`|  
|^\=|`SafeInt<T,E>& operator^= (SafeInt<T,E> rhs) throw()`|  
|^\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator^= (U rhs) throw()`|  
|^\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator^= (SafeInt<U, E> rhs) throw()`|  
|&#124;|`SafeInt<T,E> operator&#124; (SafeInt<T,E> rhs) const throw()`|  
|&#124;|`template<typename U>`<br /><br /> `SafeInt<T,E> operator&#124; (U rhs) const throw()`|  
|&#124;\=|`SafeInt<T,E>& operator&#124;= (SafeInt<T,E> rhs) throw()`|  
|&#124;\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&#124;= (U rhs) throw()`|  
|&#124;\=|`template<typename U>`<br /><br /> `SafeInt<T,E>& operator&#124;= (SafeInt<U, E> rhs) throw()`|  
  
## Comentários  
 A classe de `SafeInt` protege contra o estouro de inteiro em operações matemáticas.  Por exemplo, considere adicionar dois inteiros de 8 bits: um tem um valor de 200 e a segunda tem um valor de 100.  A operação matemática será 200 \+ 100 \= 300correta.  No entanto, devido ao limite de 8 bits, o bit de inteiro superior será perdida e o compilador retornará 44 \(300 \- 2<sup>8</sup>\) como o resultado.  Qualquer operação que dependa dessa equação matemática gerará um comportamento inesperado.  
  
 A classe de `SafeInt` verifica se um estouro aritmético ocorra ou se o código tentar dividir por zero.  Em ambos os casos, a classe chama o manipulador de erros para avisar o programa do problema potencial.  
  
 Essa classe também permite comparar dois tipos diferentes de inteiros como são objetos de `SafeInt` .  Normalmente, quando você executa uma comparação, primeiro você deve converter os números para ser o mesmo tipo.  Converter um número para outro tipo frequentemente requer verificações ter certeza de que não há perda de dados.  
  
 A tabela dos operadores neste tópico lista o matemático e os operadores de comparação com suporte por `SafeInt` classe.  A maioria dos operadores matemáticos retornam um objeto de `SafeInt` do tipo `T`.  
  
 As operações de comparação entre `SafeInt` e um tipo integral podem ser executadas em qualquer direção.  Por exemplo, `SafeInt<int>(x) < y` e `y > SafeInt<int>(x)` forem válidos e retornarão o mesmo resultado.  
  
 Muitos operadores binários não dão suporte ao uso de dois tipos diferentes de `SafeInt` .  Um exemplo disso é o operador de `&` .  `SafeInt<T, E> & int` tem suporte, mas `SafeInt<T, E> & SafeInt<U, E>` não é.  No último exemplo, o compilador não souber qual tipo de parâmetro a ser retornado.  Uma solução para esse problema é converter o segundo parâmetro de volta para o tipo de base.  Usando os mesmos parâmetros, isso pode ser feito com `SafeInt<T, E> & (U)SafeInt<U, E>`.  
  
> [!NOTE]
>  Para todos os operação bit a bit, os dois parâmetros diferentes devem ser do mesmo tamanho.  Se os tamanhos diferentes, o compilador gerará uma exceção de [ASSERT](../Topic/ASSERT%20\(MFC\).md) .  Os resultados dessa operação não podem ser certamente precisos.  Para resolver esse problema, converter o parâmetro menor até que seja o mesmo tamanho que o parâmetro maior.  
  
 Para os operadores de troca, deslocando bit mais do que existem para o tipo de modelo lançarão uma exceção AFIRMAR.  Isso não terá nenhum efeito no modo de versão.  Mesclar dois tipos de parâmetros de SafeInt é possível que os operadores de troca como o tipo de retorno é o mesmo que o tipo original.  O número à direita do operador apenas indica o número de bits para turno.  
  
 Quando você executa uma comparação lógica com um objeto de SafeInt, a comparação é estritamente aritmética.  Por exemplo, considere essas expressões:  
  
-   `SafeInt<uint>((uint)~0) > -1`  
  
-   `((uint)~0) > -1`  
  
 A primeira instrução resolve a `true`, mas a segunda resoluções da `false`.  A negação bit a bit de 0 é 0xFFFFFFFF.  Na segunda instrução, o operador de comparação padrão compara 0xFFFFFFFF a 0xFFFFFFFF e considera\-o ser iguais.  O operador de comparação para a classe de `SafeInt` percebe que o segundo parâmetro for negativo enquanto o primeiro parâmetro é não assinado.  Em virtude disso, embora a representação de bit são idênticas, o operador lógico de `SafeInt` que contém o número inteiro sem sinal é maior que \-1.  
  
 Tenha cuidado ao usar a classe de `SafeInt` com o operador ternário de `?:` .  Considere a seguinte linha de código.  
  
```  
Int x = flag ? SafeInt<unsigned int>(y) : -1;  
```  
  
 O compilador convertê\-la nesta:  
  
```  
Int x = flag ? SafeInt<unsigned int>(y) : SafeInt<unsigned int>(-1);  
```  
  
 Se `flag` é `false`, o compilador gerará uma exceção em vez de atribuir o valor de \-1 a `x`.  Em virtude disso, para evitar esse comportamento, o código correto para usar é a linha seguinte.  
  
```  
Int x = flag ? (int) SafeInt<unsigned int>(y) : -1;  
```  
  
 `T` e `U` podem ser atribuídos a um tipo booliano, o tipo de caractere, ou o tipo inteiro.  Tipos inteiros podem ser assinados ou não assinados e qualquer tamanho de 8 bits para 64 bits.  
  
> [!NOTE]
>  Embora a classe de `SafeInt` aceita qualquer tipo de inteiro, executa com mais eficiência utilizando tipos sem assinatura.  
  
 `E` é o mecanismo de tratamento de erros que `SafeInt` usa.  Dois mecanismos de tratamento de erros são fornecidos com a biblioteca de SafeInt.  A política padrão é `SafeIntErrorPolicy_SafeIntException`, que gerencie uma exceção de [Classe SafeIntException](../windows/safeintexception-class.md) quando ocorre um erro.  A outra política é `SafeIntErrorPolicy_InvalidParameter`, para que o programa se ocorrer um erro.  
  
 Há duas opções para personalizar a política de erro.  A primeira opção é definir o parâmetro `E` quando você cria `SafeInt`.  Use essa opção quando quiser alterar a política de tratamento de erros para apenas um `SafeInt`.  Outra opção é definir `_SAFEINT_DEFAULT_ERROR_POLICY` para ser a classe de tratamento de erros personalizado antes que você inclua a biblioteca de `SafeInt` .  Use essa opção quando quiser alterar a política padrão de tratamento de erros para todas as instâncias de classe de `SafeInt` em seu código.  
  
> [!NOTE]
>  Uma classe personalizada que trata erros de biblioteca de SafeInt não deve retornar o controle ao código que chamou o manipulador de erros.  Depois que o manipulador de erros é chamado, o resultado da operação de `SafeInt` não pode ser confiável.  
  
## Requisitos  
 **Cabeçalho:** safeint.h  
  
 msl::utilities de**Namespace:**  
  
## Consulte também  
 [Miscellaneous Support Libraries Classes](http://msdn.microsoft.com/pt-br/406fd46e-d53f-4096-ab40-36aa754c7a5c)   
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeIntException](../windows/safeintexception-class.md)