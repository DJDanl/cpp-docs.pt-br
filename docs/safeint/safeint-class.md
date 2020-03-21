---
title: Classe SafeInt
ms.date: 10/22/2018
ms.topic: reference
f1_keywords:
- SafeInt
- SafeInt::SafeInt
- SafeInt.SafeInt
helpviewer_keywords:
- SafeInt class
- SafeInt class, constructor
ms.assetid: 27a8f087-2511-46f9-8d76-2aeb66ca272f
ms.openlocfilehash: c69dc7ed5e34d98d5acff8f2bc28c34761bd31c6
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076813"
---
# <a name="safeint-class"></a>Classe SafeInt

Estende as primitivas de inteiro para ajudar a evitar o estouro de inteiro e permite comparar diferentes tipos de inteiros.

> [!NOTE]
> A última versão dessa biblioteca está localizada em [https://github.com/dcleblanc/SafeInt](https://github.com/dcleblanc/SafeInt).

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, typename E = _SAFEINT_DEFAULT_ERROR_POLICY>
class SafeInt;
```

### <a name="parameters"></a>parâmetros

| Modelo  |  DESCRIÇÃO |
|--------|------------|
| T         |  O tipo de inteiro ou parâmetro booliano que `SafeInt` substitui. |
| E         |  Um tipo de dados enumerados que define a política de tratamento de erro. |
| U         |  O tipo de inteiro ou parâmetro booliano para o operando secundário. |

| Parâmetro  |  DESCRIÇÃO |
|---------|-----------------|
| *rhs*      |  [in] Um parâmetro de entrada que representa o valor no lado direito do operador em várias funções independentes. |
| *i*        |  [in] Um parâmetro de entrada que representa o valor no lado direito do operador em várias funções independentes. |
| *bits*     |  [in] Um parâmetro de entrada que representa o valor no lado direito do operador em várias funções independentes. |

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

| Nome                          |  DESCRIÇÃO |
|---------------------------|--------------------|
| [SafeInt::SafeInt](#safeint)  |  Construtor padrão. |

### <a name="assignment-operators"></a>Operadores de atribuição

| Nome  |  Sintaxe |
|----|---------|
| =     |  `template<typename U>`<br />`SafeInt<T,E>& operator= (const U& rhs)` |
| =     |  `SafeInt<T,E>& operator= (const T& rhs) throw()` |
| =     |  `template<typename U>`<br />`SafeInt<T,E>& operator= (const SafeInt<U, E>& rhs)` |
| =     |  `SafeInt<T,E>& operator= (const SafeInt<T,E>& rhs) throw()` |

### <a name="casting-operators"></a>Operadores de conversão

| Nome              |  Sintaxe |
|------|---------------------------------|
| bool              |  `operator bool() throw()` |
| char              |  `operator char() const` |
| signed char       |  `operator signed char() const` |
| unsigned char     |  `operator unsigned char() const` |
| __int16           |  `operator __int16() const` |
| unsigned __int16  |  `operator unsigned __int16() const` |
| __int32           |  `operator __int32() const` |
| unsigned __int32  |  `operator unsigned __int32() const` |
| long              |  `operator long() const` |
| unsigned long     |  `operator unsigned long() const` |
| __int64           |  `operator __int64() const` |
| unsigned __int64  |  `operator unsigned __int64() const` |
| wchar_t           |  `operator wchar_t() const` |

### <a name="comparison-operators"></a>Operadores de comparação

| Nome  |  Sintaxe |
|----|----------------|
| \<     |  `template<typename U>`<br /><br /> `bool operator< (U rhs) const throw()` |
| \<     |  `bool operator< (SafeInt<T,E> rhs) const throw()` |
| \>=    |  `template<typename U>`<br /><br /> `bool operator>= (U rhs) const throw()` |
| \>=    |  `Bool operator>= (SafeInt<T,E> rhs) const throw()` |
| \>     |  `template<typename U>`<br /><br /> `bool operator> (U rhs) const throw()` |
| \>     |  `Bool operator> (SafeInt<T,E> rhs) const throw()` |
| \<=    |  `template<typename U>`<br /><br /> `bool operator<= (U rhs) const throw()` |
| \<=    |  `bool operator<= (SafeInt<T,E> rhs) const throw()` |
| ==    |  `template<typename U>`<br /><br /> `bool operator== (U rhs) const throw()` |
| ==    |  `bool operator== (bool rhs) const throw()` |
| ==    |  `bool operator== (SafeInt<T,E> rhs) const throw()` |
| !=    |  `template<typename U>`<br /><br /> `bool operator!= (U rhs) const throw()` |
| !=    |  `bool operator!= (bool b) const throw()` |
| !=    |  `bool operator!= (SafeInt<T,E> rhs) const throw()` |

### <a name="arithmetic-operators"></a>Operadores aritméticos

| Nome  |  Sintaxe |
|----|--------------|
| +     |  `const SafeInt<T,E>& operator+ () const throw()` |
| -     |  `SafeInt<T,E> operator- () const` |
| ++    |  `SafeInt<T,E>& operator++ ()` |
| --    |  `SafeInt<T,E>& operator-- ()` |
| %     |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator% (U rhs) const` |
| %     |  `SafeInt<T,E> operator% (SafeInt<T,E> rhs) const` |
| %=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator%= (U rhs)` |
| %=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator%= (SafeInt<U, E> rhs)` |
| \*     |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator* (U rhs) const` |
| \*     |  `SafeInt<T,E> operator* (SafeInt<T,E> rhs) const` |
| \*=    |  `SafeInt<T,E>& operator*= (SafeInt<T,E> rhs)` |
| \*=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator*= (U rhs)` |
| \*=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator*= (SafeInt<U, E> rhs)` |
| /     |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator/ (U rhs) const` |
| /     |  `SafeInt<T,E> operator/ (SafeInt<T,E> rhs ) const` |
| /=    |  `SafeInt<T,E>& operator/= (SafeInt<T,E> i)` |
| /=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator/= (U i)` |
| /=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator/= (SafeInt<U, E> i)` |
| +     |  `SafeInt<T,E> operator+ (SafeInt<T,E> rhs) const` |
| +     |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator+ (U rhs) const` |
| +=    |  `SafeInt<T,E>& operator+= (SafeInt<T,E> rhs)` |
| +=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator+= (U rhs)` |
| +=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator+= (SafeInt<U, E> rhs)` |
| -     |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator- (U rhs) const` |
| -     |  `SafeInt<T,E> operator- (SafeInt<T,E> rhs) const` |
| -=    |  `SafeInt<T,E>& operator-= (SafeInt<T,E> rhs)` |
| -=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator-= (U rhs)` |
| -=    |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator-= (SafeInt<U, E> rhs)` |

### <a name="logical-operators"></a>Operadores lógicos

| Nome     |  Sintaxe |
|------|--------------|
| !        |  `bool operator !() const throw()` |
| ~        |  `SafeInt<T,E> operator~ () const throw()` |
| \<\<       |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator<< (U bits) const throw()` |
| \<\<       |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator<< (SafeInt<U, E> bits) const throw()` |
| \<\<=      |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator<<= (U bits) throw()` |
| \<\<=      |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator<<= (SafeInt<U, E> bits) throw()` |
| \>\>       |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator>> (U bits) const throw()` |
| \>\>       |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator>> (SafeInt<U, E> bits) const throw()` |
| \>\>=      |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator>>= (U bits) throw()` |
| \>\>=      |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator>>= (SafeInt<U, E> bits) throw()` |
| &        |  `SafeInt<T,E> operator& (SafeInt<T,E> rhs) const throw()` |
| &        |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator& (U rhs) const throw()` |
| &=       |  `SafeInt<T,E>& operator&= (SafeInt<T,E> rhs) throw()` |
| &=       |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator&= (U rhs) throw()` |
| &=       |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator&= (SafeInt<U, E> rhs) throw()` |
| ^        |  `SafeInt<T,E> operator^ (SafeInt<T,E> rhs) const throw()` |
| ^        |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator^ (U rhs) const throw()` |
| ^=       |  `SafeInt<T,E>& operator^= (SafeInt<T,E> rhs) throw()` |
| ^=       |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator^= (U rhs) throw()` |
| ^=       |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator^= (SafeInt<U, E> rhs) throw()` |
| &#124;   |  `SafeInt<T,E> operator&#124; (SafeInt<T,E> rhs) const throw()` |
| &#124;   |  `template<typename U>`<br /><br /> `SafeInt<T,E> operator&#124; (U rhs) const throw()` |
| &#124;=  |  `SafeInt<T,E>& operator&#124;= (SafeInt<T,E> rhs) throw()` |
| &#124;=  |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator&#124;= (U rhs) throw()` |
| &#124;=  |  `template<typename U>`<br /><br /> `SafeInt<T,E>& operator&#124;= (SafeInt<U, E> rhs) throw()` |

## <a name="remarks"></a>Comentários

A classe `SafeInt` protege contra o estouro de inteiros em operações matemáticas. Por exemplo, considere adicionar dois inteiros de 8 bits: um tem o valor 200, o outro, 100. A operação matemática correta seria 200 + 100 = 300. No entanto, devido ao limite de inteiros de 8 bits, o bit superior será perdido, e o compilador retornará como resultado 44 (300 - 2<sup>8</sup>). Qualquer operação que depender dessa equação matemática gerará um comportamento inesperado.

A classe `SafeInt` verifica se um estouro aritmético ocorreu ou se o código tenta dividir por zero. Em ambos os casos, a classe chama o manipulador de erro para avisar o programa sobre o possível problema.

Essa classe também permite comparar dois tipos diferentes de inteiros, desde que sejam objetos `SafeInt`. Normalmente, quando você executa uma comparação, primeiro deve converter os números no mesmo tipo. Converter um número em outro tipo geralmente requer verificações para garantir que não haja perda de dados.

A tabela Operadores neste tópico mostra os operadores matemáticos e de comparação compatíveis com a classe `SafeInt`. A maioria dos operadores matemáticos retorna um objeto `SafeInt` do tipo `T`.

Operações de comparação entre um `SafeInt` e um tipo integral podem ser executadas em qualquer direção. Por exemplo, `SafeInt<int>(x) < y` e `y> SafeInt<int>(x)` são válidos e retornarão o mesmo resultado.

Muitos operadores binários não são compatíveis com o uso de dois tipos `SafeInt` diferentes. Um exemplo disso é o operador `&`. É compatível com `SafeInt<T, E> & int`, mas não com `SafeInt<T, E> & SafeInt<U, E>`. No último exemplo, o compilador não sabe o tipo de parâmetro a ser retornado. Uma solução para esse problema é converter o segundo parâmetro de volta no tipo base. Usando os mesmos parâmetros, isso pode ser feito com `SafeInt<T, E> & (U)SafeInt<U, E>`.

> [!NOTE]
> Para qualquer operação bit a bit, os dois parâmetros diferentes devem ter o mesmo tamanho. Se os tamanhos forem diferentes, o compilador lançará uma exceção [ASSERT](../mfc/reference/diagnostic-services.md#assert). Não há garantia de que os resultados dessa operação sejam precisos. Para resolver esse problema, converta o parâmetro menor até que ele tenha o mesmo tamanho do parâmetro maior.

Para operadores de deslocamento, a mudança para mais bits do que existe para o tipo de modelo lançará uma exceção ASSERT. Isso não terá efeito no modo de liberação. A combinação de dois tipos de parâmetros SafeInt é possível para os operadores shift porque o tipo de retorno é o mesmo do tipo original. O número no lado direito do operador indica apenas o número de bits a serem alterados.

Quando você realiza uma comparação lógica com um objeto SafeInt, essa comparação é estritamente aritmética. Por exemplo, considere estas expressões:

- `SafeInt<uint>((uint)~0) > -1`

- `((uint)~0) > -1`

A primeira instrução é resolvida como **true**, mas a segunda instrução é resolvida como `false`. A negação bit a bit de 0 é 0xFFFFFFFF. Na segunda instrução, o operador de comparação padrão compara 0xFFFFFFFF a 0xFFFFFFFF e os considera iguais. O operador de comparação da classe `SafeInt` percebe que o segundo parâmetro é negativo, enquanto o primeiro não tem sinal. Portanto, apesar de a representação de bits ser idêntica, o operador lógico `SafeInt` percebe que o inteiro sem sinal é maior que -1.

Tenha cuidado ao usar a classe `SafeInt` junto com o operador ternário `?:`. Considere a seguinte linha de código.

```cpp
Int x = flag ? SafeInt<unsigned int>(y) : -1;
```

O compilador converte isso no seguinte:

```cpp
Int x = flag ? SafeInt<unsigned int>(y) : SafeInt<unsigned int>(-1);
```

Se `flag` for `false`, o compilador lançará uma exceção em vez de atribuir o valor de -1 a `x`. Portanto, para evitar esse comportamento, o código correto a ser usado é a seguinte linha.

```cpp
Int x = flag ? (int) SafeInt<unsigned int>(y) : -1;
```

`T` e `U` podem receber um tipo booliano, um tipo caractere ou um tipo inteiro. Os tipos inteiros podem ser assinados ou não assinados e ter qualquer tamanho de 8 a 64 bits.

> [!NOTE]
> Embora a classe `SafeInt` aceite qualquer tipo inteiro, seu desempenho de execução é melhor com tipos sem sinal.

`E` é o mecanismo de tratamento de erro usado por `SafeInt`. Dois mecanismos de tratamento de erro são fornecidos com a biblioteca SafeInt. A política padrão é `SafeIntErrorPolicy_SafeIntException`, que gera uma exceção [SafeIntException Class](../safeint/safeintexception-class.md) quando ocorre um erro. A outra política é `SafeIntErrorPolicy_InvalidParameter`, que interromperá o programa se ocorrer um erro.

Existem duas opções para personalizar a política de erro. A primeira opção é definir o parâmetro `E` quando você cria um `SafeInt`. Use essa opção quando quiser alterar a política de tratamento de erro para apenas um `SafeInt`. A outra opção é definir _SAFEINT_DEFAULT_ERROR_POLICY como sua classe personalizada de tratamento de erro antes de incluir a biblioteca `SafeInt`. Use essa opção quando quiser mudar a política de tratamento de erros padrão para todas as instâncias da classe `SafeInt` no seu código.

> [!NOTE]
> Uma classe personalizada que manipula erros da biblioteca SafeInt não deve retornar o controle para o código que chamou o manipulador de erros. Após a chamada do manipulador de erro, o resultado da operação `SafeInt` não poderá ser confiável.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SafeInt`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint.h

**Namespace:** msl::utilities

## <a name="safeintsafeint"></a><a name="safeint"></a>SafeInt::SafeInt

Constrói um objeto `SafeInt`.

```cpp
SafeInt() throw

SafeInt (
   const T& i
) throw ()

SafeInt (
   bool b
) throw ()

template <typename U>
SafeInt (
   const SafeInt <U, E>& u
)

I template <typename U>
SafeInt (
   const U& i
)
```

### <a name="parameters"></a>parâmetros

*i*<br/>
[in] O valor do novo objeto `SafeInt`. Este deve ser um parâmetro do tipo T ou U, dependendo do construtor.

*b*<br/>
[in] O valor booliano do novo objeto `SafeInt`.

*u*<br/>
[in] Um `SafeInt` do tipo U. O novo objeto `SafeInt` terá o mesmo valor que *u*, mas será do tipo T.

U O tipo de dados armazenados em `SafeInt`. Isso pode ser um tipo booliano, caractere ou inteiro. Se for um tipo inteiro, ele poderá ser assinado ou não assinado e ter entre 8 e 64 bits.

### <a name="remarks"></a>Comentários

O parâmetro de entrada para o construtor, *i* ou *u*, deve ser um tipo booliano, caractere ou inteiro. Se for outro tipo de parâmetro, a classe `SafeInt` chamará [static_assert](../cpp/static-assert.md) para indicar um parâmetro de entrada inválido.

Os construtores que usam o tipo modelo `U` convertem automaticamente o parâmetro de entrada no tipo especificado por `T`. A classe `SafeInt` converte os dados sem perda de dados. Ela informa o manipulador de erro `E` quando não consegue converter os dados no tipo `T` sem perda de dados.

Se você criar um `SafeInt` de um parâmetro booliano, precisará inicializar o valor imediatamente. Não é possível construir um `SafeInt` usando o código `SafeInt<bool> sb;`. Isso gerará um erro de compilação.
