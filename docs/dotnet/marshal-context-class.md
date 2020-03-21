---
title: Classe marshal_context
ms.date: 01/16/2019
ms.topic: reference
f1_keywords:
- msclr::interop::marshal_context::marshal_context
- msclr::interop::marshal_context::marshal_as
helpviewer_keywords:
- msclr::marshal_context class [C++]
ms.assetid: 241b0cf6-4ca4-4812-aaee-d671c11dc034
ms.openlocfilehash: 7fb22754248e66d7a20292af41a8e1b8ba050451
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80080028"
---
# <a name="marshal_context-class"></a>Classe marshal_context

Essa classe converte dados entre ambientes nativos e gerenciados.

## <a name="syntax"></a>Sintaxe

```cpp
class marshal_context
```

## <a name="remarks"></a>Comentários

Use a classe `marshal_context` para conversões de dados que exigem um contexto. Para obter mais informações sobre quais conversões exigem um contexto e qual arquivo de marshaling deve ser incluído, consulte [visão geral do marshaling C++em ](../dotnet/overview-of-marshaling-in-cpp.md). O resultado do marshaling quando você usa um contexto é válido somente até que o objeto de `marshal_context` seja destruído. Para preservar o resultado, você deve copiar os dados.

O mesmo `marshal_context` pode ser usado para várias conversões de dados. A reutilização do contexto dessa maneira não afetará os resultados das chamadas de marshaling anteriores.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|---------|-----------|
|[marshal_context::marshal_context](#marshal-context)|Constrói um objeto `marshal_context` a ser usado para conversão de dados entre tipos de dados gerenciados e nativos.|
|[marshal_context::~marshal_context](#tilde-marshal-context)|Destrói um objeto `marshal_context`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|---------|-----------|
|[marshal_context::marshal_as](#marshal-as)|Executa o marshaling em um objeto de dados específico para convertê-lo entre um tipo de dados gerenciado e um nativo.|

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr \ marshal_windows. h >, \<msclr \ marshal_cppstd. h > ou \<msclr \ marshal_atl. h >

**Namespace:** msclr:: Interop

## <a name="marshal_contextmarshal_context"></a><a name="marshal-context"></a>marshal_context:: marshal_context

Constrói um objeto `marshal_context` a ser usado para conversão de dados entre tipos de dados gerenciados e nativos.

```cpp
marshal_context();
```

### <a name="remarks"></a>Comentários

Algumas conversões de dados exigem um contexto de marshaling. Para obter mais informações sobre quais traduções exigem um contexto e qual arquivo de marshaling deve ser incluído em seu aplicativo, consulte [visão geral C++do marshaling in ](../dotnet/overview-of-marshaling-in-cpp.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [marshal_context:: marshal_as](../dotnet/marshal-context-marshal-as.md).

## <a name="marshal_contextmarshal_context"></a><a name="tilde-marshal-context"></a>marshal_context:: ~ marshal_context

Destrói um objeto `marshal_context`.

```cpp
~marshal_context();
```

### <a name="remarks"></a>Comentários

Algumas conversões de dados exigem um contexto de marshaling. Consulte [visão geral do marshaling C++ em](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais traduções exigem um contexto e qual arquivo de marshaling deve ser incluído em seu aplicativo.

A exclusão de um objeto de `marshal_context` invalidará os dados convertidos por esse contexto. Se você quiser preservar seus dados depois que um objeto `marshal_context` for destruído, você deverá copiar manualmente os dados para uma variável que persistirá.

## <a name="marshal_contextmarshal_as"></a><a name="marshal-as"></a>marshal_context:: marshal_as

Executa o marshaling em um objeto de dados específico para convertê-lo entre um tipo de dados gerenciado e um nativo.

```cpp
To_Type marshal_as<To_Type>(
   From_Type input
);
```

### <a name="parameters"></a>parâmetros

*input*<br/>
no O valor que você deseja realizar marshaling em uma variável `To_Type`.

### <a name="return-value"></a>Valor retornado

Uma variável do tipo `To_Type` que é o valor convertido de `input`.

### <a name="remarks"></a>Comentários

Essa função executa o marshaling em um objeto de dados específico. Use essa função somente com as conversões indicadas pela tabela em [visão geral do marshaling no C++ ](../dotnet/overview-of-marshaling-in-cpp.md).

Se você tentar realizar marshaling de um par de tipos de dados que não têm suporte, `marshal_as` gerará um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) no momento da compilação. Leia a mensagem fornecida com esse erro para obter mais informações. O erro de `C4996` pode ser gerado para mais do que apenas funções preteridas. Duas condições que geram esse erro estão tentando realizar marshaling de um par de tipos de dados que não têm suporte e tentando usar `marshal_as` para uma conversão que requer um contexto.

A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se precisar de outras conversões. A tabela no `Marshaling Overview in C++` indica qual arquivo de marshaling deve ser incluído para cada conversão.

### <a name="example"></a>Exemplo

Este exemplo cria um contexto para realizar o marshaling de um `System::String` para um tipo de variável `const char *`. Os dados convertidos não serão válidos após a linha que exclui o contexto.

```cpp
// marshal_context_test.cpp
// compile with: /clr
#include <stdlib.h>
#include <string.h>
#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;

int main() {
   marshal_context^ context = gcnew marshal_context();
   String^ message = gcnew String("Test String to Marshal");
   const char* result;
   result = context->marshal_as<const char*>( message );
   delete context;
   return 0;
}
```