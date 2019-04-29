---
title: Classe Platform::String
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::String::String
- VCCORLIB/Platform::String::Begin
- VCCORLIB/Platform::String::CompareOrdinal
- VCCORLIB/Platform::String::Concat
- VCCORLIB/Platform::String::Data
- VCCORLIB/Platform::String::Dispose
- VCCORLIB/Platform::String::End
- VCCORLIB/Platform::String::Equals
- VCCORLIB/Platform::String::GetHashCode
- VCCORLIB/Platform::String::IsEmpty
- VCCORLIB/Platform::String::IsFastPass
- VCCORLIB/Platform::String::Length
- VCCORLIB/Platform::String::ToString
helpviewer_keywords:
- Platform::String
ms.assetid: 72dd04a4-a694-40d3-b899-eaa0b503eab8
ms.openlocfilehash: 0b8a29efc5b18432eabfeddc75af12737538281c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62330200"
---
# <a name="platformstring-class"></a>Classe Platform::String

Representa uma coleção sequencial de caracteres Unicode que é usada para representar o texto. Para obter mais informações e exemplos, consulte [cadeias de caracteres](../cppcx/strings-c-cx.md).

## <a name="syntax"></a>Sintaxe

```cpp
public ref class String sealed : Object,
    IDisposable,
    IEquatable,
    IPrintable
```

## <a name="iterators"></a>Iterators

Duas funções de iterador, que não são membros da classe String, podem ser usadas com a função modelo `std::for_each` para enumerar os caracteres em um objeto String.

|Membro|Descrição|
|------------|-----------------|
|`const char16* begin(String^ s)`|Retorna um ponteiro para o início do objeto String especificado.|
|`const char16* end(String^ s)`|Retorna um ponteiro após o fim do objeto String especificado.|

### <a name="members"></a>Membros

A classe String herda de Object das interfaces IDisposable, IEquatable e IPrintable.

A classe String também tem os tipos de membros a seguir.

**Construtores**

|Membro|Descrição|
|------------|-----------------|
|[String::String](#ctor)|Inicializa uma nova instância da classe String.|

**Métodos**

A classe String herda os métodos Equals(), Finalize(), GetHashCode(), GetType(), MemberwiseClose() e ToString() da [Platform::Object Class](../cppcx/platform-object-class.md). String também tem os métodos a seguir.

|Método|Descrição|
|------------|-----------------|
|[String::Begin](#begin)|Retorna um ponteiro para o início da cadeia de caracteres atual.|
|[String::CompareOrdinal](#compareordinal)|Compara dois objetos `String` avaliando os valores numéricos dos caracteres correspondentes nos dois valores de cadeias de caracteres representados pelos objetos.|
|[String::Concat](#concat)|Concatena os valores de dois objetos String.|
|[String::Data](#data)|Retorna um ponteiro para o início da cadeia de caracteres atual.|
|[String::Dispose](#dispose)|Libera recursos.|
|[String::End](#end)|Retorna um ponteiro após o fim da cadeia de caracteres atual.|
|[String::Equals](#equals)|indica se o objeto especificado é igual ao objeto atual.|
|[String::GetHashCode](#gethashcode)|Retorna o código hash para essa instância.|
|[String::IsEmpty](#isempty)|Indica se o objeto String atual está vazio.|
|[String::IsFastPass](#isfastpass)|Indica se o objeto String atual está participando de uma *passagem rápida* operação. Em uma operação de passagem rápida, a contagem de referência é suspensa.|
|[String::Length](#length)|Recupera o comprimento do objeto String atual.|
|[String::ToString](#tostring)|Retorna um objeto String cujo valor é igual ao da cadeia de caracteres atual.|

**Operadores**

A classe de cadeia de caracteres tem os seguintes operadores.

|Membro|Descrição|
|------------|-----------------|
|[String:: Operator = = operador](#operator-equality)|Indica se dois objetos String especificados têm o mesmo valor.|
|[operador+ Operador](#operator-plus)|Concatena dois objetos de cadeia de caracteres em um novo objeto de cadeia de caracteres.|
|[String:: Operator > operador](#operator-greater-than)|Indica se o valor de um objeto String é maior que o valor de um segundo objeto String.|
|[String:: Operator > = operador](#operator-greater-than-or-equals)|Indica se o valor de um objeto String é maior ou igual ao valor de um segundo objeto String.|
|[String:: Operator! = operador](#operator-inequality)|Indica se dois objetos String especificados têm valores diferentes.|
|[String:: Operator < operador](#operator-less-than)|Indica se o valor de um objeto String é menor que o valor de um segundo objeto String.|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Cabeçalho** vccorlib.h (incluído por padrão)

## <a name="begin"></a>  Método String:: begin

Retorna um ponteiro para o início da cadeia de caracteres atual.

### <a name="syntax"></a>Sintaxe

```cpp
char16* Begin();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o início da cadeia de caracteres atual.

## <a name="compareordinal"></a>  Método String:: CompareOrdinal

Compara dois objetos `String` avaliando os valores numéricos dos caracteres correspondentes nos dois valores de cadeias de caracteres representados pelos objetos.

### <a name="syntax"></a>Sintaxe

```cpp
int CompareOrdinal( String^ str1, String^ str2 );
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto String.

*str2*<br/>
O segundo objeto String.

### <a name="return-value"></a>Valor de retorno

Um número inteiro que indica a relação lexical entre os dois termos de comparação. A tabela a seguir lista os possíveis valores de retorno.

|Valor|Condição|
|-----------|---------------|
|-1|`str1` é menor que `str2`.|
|0|`str1` é igual a `str2`.|
|1|`str1` é maior que `str2`.|

## <a name="concat"></a>  Método String:: concat

Concatena os valores de dois objetos String.

### <a name="syntax"></a>Sintaxe

```cpp
String^ Concat( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto String ou `null`.

*str2*<br/>
O segundo objeto String ou `null`.

### <a name="return-value"></a>Valor de retorno

Um novo objeto String^ cujo valor é a concatenação dos valores de `str1` e `str2`.

Se `str1` for `null` e `str2` não for, `str1` será retornado. Se `str2` for `null` e `str1` não for, `str2` será retornado. Se `str1` e `str2` forem ambos `null`, a cadeia de caracteres vazia (L"") será retornada.

## <a name="data"></a>  Método String:: data

Retorna um ponteiro para o início do buffer de dados do objeto como uma matriz de estilo C de elementos `char16` (`wchar_t`).

### <a name="syntax"></a>Sintaxe

```
const char16* Data();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o início de uma `const char16` matriz de caracteres Unicode (`char16` é um typedef para `wchar_t`).

### <a name="remarks"></a>Comentários

Use este método para converter de `Platform::String^` em `wchar_t*`. Quando o objeto `String` sai do escopo, não há mais garantia de que ponteiro Dados seja válido. Para armazenar os dados além do tempo de vida de original `String` do objeto, use [wcscpy_s](../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md) para copiar a matriz na memória que você mesmo atribuiu.

## <a name="dispose"></a>  Método String:: Dispose

Libera recursos.

### <a name="syntax"></a>Sintaxe

```cpp
virtual override void Dispose();
```

## <a name="end"></a>  Método String:: end

Retorna um ponteiro após o fim da cadeia de caracteres atual.

### <a name="syntax"></a>Sintaxe

```cpp
char16* End();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro após o fim da cadeia de caracteres atual.

### <a name="remarks"></a>Comentários

End () retorna begin + Length.

## <a name="equals"></a>  Método String:: Equals

Indica se a cadeia de caracteres especificada tem o mesmo valor que o objeto atual.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::Equals(Object^ str);
bool String::Equals(String^ str);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O objeto a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se `str` for igual ao objeto atual; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Esse método é equivalente a [String:: CompareOrdinal](#compareordinal). Na primeira sobrecarga, é esperado que o parâmetro `str` possa ser convertido em um objeto String^.

## <a name="gethashcode"></a>  Método String:: GetHashCode

Retorna o código hash para essa instância.

### <a name="syntax"></a>Sintaxe

```cpp
virtual override int GetHashCode();
```

### <a name="return-value"></a>Valor de retorno

O código hash para essa instância.

## <a name="isempty"></a>  Método String:: IsEmpty

Indica se o objeto String atual está vazio.

### <a name="syntax"></a>Sintaxe

```cpp
bool IsEmpty();
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se atual `String` objeto é **nulo** ou cadeia de caracteres vazia (L""); caso contrário, **false**.

## <a name="isfastpass"></a>  Método String:: isfastpass

Indica se o objeto String atual está participando de uma *passagem rápida* operação. Em uma operação de passagem rápida, a contagem de referência é suspensa.

### <a name="syntax"></a>Sintaxe

```cpp
bool IsFastPass();
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o atual `String` objeto for fast-past; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Em uma chamada à função em que um objeto contado por referência é um parâmetro e a função chamada somente lê esse objeto, o compilador pode suspender com segurança a contagem de referência e aprimorar o desempenho de chamada. Não há nada útil que seu código pode fazer com essa propriedade. O sistema manipula todos os detalhes.

## <a name="length"></a>  Método String:: Length

Recupera o número de caracteres atual `String` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned int Length();
```

### <a name="return-value"></a>Valor de retorno

O número de caracteres atual `String` objeto.

### <a name="remarks"></a>Comentários

O comprimento de uma cadeia de caracteres sem caracteres é zero. O comprimento da seguinte cadeia de caracteres é 5:

```cpp
String^ str = "Hello";
int len = str->Length(); //len = 5
```

A matriz de caracteres retornada pela [String:: data](#data) tem um caractere adicional, que é o NULL de terminação ou '\0'. Esse caractere também tem dois bytes de tamanho.

## <a name="operator-plus"></a>  Operador String:: Operator +

Concatena duas [cadeia de caracteres](../cppcx/platform-string-class.md) objetos em uma nova [cadeia de caracteres](../cppcx/platform-string-class.md) objeto.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::operator+( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto `String`.

*str2*<br/>
O segundo objeto `String` , cujo conteúdo será acrescentado a `str1`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se *str1* é igual a *str2*; caso contrário, **false**.

### <a name="remarks"></a>Comentários

O operador cria um objeto `String^` que contém os dados dos dois operandos. Use-o de acordo com sua conveniência quando o desempenho extremo não for crítico. Algumas chamadas para “`+`” em uma função provavelmente não serão visíveis, mas se você estiver manipulando objetos grandes ou dados de texto em um loop estreito, use os mecanismos e os tipos de C++ padrão.

##  <a name="operator-equality"></a> String:: Operator = = operador

Indica se dois objetos de cadeia de caracteres especificados têm o mesmo valor de texto.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::operator==( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto `String` a ser comparado.

*str2*<br/>
O segundo objeto `String` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o conteúdo de `str1` são iguais às `str2`; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esse operador é equivalente a [String:: CompareOrdinal](#compareordinal).

##  <a name="operator-greater-than"></a>  String::operator&gt;

Indica se o valor de um `String` objeto é maior que o valor de um segundo `String` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::operator>( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto `String`.

*str2*<br/>
O segundo objeto `String`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o valor da `str1` é maior que o valor de `str2`; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esse operador é equivalente a chamar explicitamente [String:: CompareOrdinal](#compareordinal) e obter um resultado maior que zero.

## <a name="operator-greater-than-or-equals"></a> String::operator&gt;=

Indica se o valor de um `String` objeto é maior que ou igual ao valor de um segundo `String` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::operator>=( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto `String`.

*str2*<br/>
O segundo objeto `String`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o valor da `str1` é maior que ou igual ao valor de `str2`; caso contrário, **false**.

## <a name="operator-inequality"></a> String::operator!=

Indica se duas especificadas `String` objetos têm valores diferentes.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::operator!=( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto `String` a ser comparado.

*str2*<br/>
O segundo objeto `String` a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se `str1` não é igual a `str2`; caso contrário, **false**.

## <a name="operator-less-than"></a> String::operator&lt;

Indica se o valor de um `String` objeto é menor que o valor de um segundo `String` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
bool String::operator<( String^ str1, String^ str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro objeto `String`.

*str2*<br/>
O segundo objeto `String`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o valor da *str1* é menor que o valor de *str2*; caso contrário, **false**.

## <a name="ctor"></a> Construtor String:: String

Inicializa uma nova instância do `String` classe com uma cópia dos dados de cadeia de caracteres de entrada.

### <a name="syntax"></a>Sintaxe

```cpp
String();
String(char16* s);
String(char16* s, unsigned int n);
```

### <a name="parameters"></a>Parâmetros

*s*<br/>
Uma série de caracteres largos que inicializam a cadeia de caracteres. char16

*n*<br/>
Um número que especifica o comprimento da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Se o desempenho for crítico e você controlar o tempo de vida da cadeia de caracteres de origem, você pode usar [stringreference](../cppcx/platform-stringreference-class.md) no lugar da cadeia de caracteres.
### <a name="example"></a>Exemplo

```cpp
String^ s = L"Hello!";
```

## <a name="tostring"></a> String::ToString

Retorna um `String` objeto cujo valor é o mesmo que a cadeia de caracteres atual.

### <a name="syntax"></a>Sintaxe

```cpp
String^ String::ToString();
```

### <a name="return-value"></a>Valor de retorno

Um `String` objeto cujo valor é o mesmo que a cadeia de caracteres atual.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
