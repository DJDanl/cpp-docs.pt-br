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
ms.openlocfilehash: 25fc2be80ba0e5d8c7f76cee1f22eed4d1bb4fc7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384862"
---
# <a name="marshalcontext-class"></a>Classe marshal_context

Essa classe converte dados entre ambientes nativos e gerenciados.

## <a name="syntax"></a>Sintaxe

```cpp
class marshal_context
```

## <a name="remarks"></a>Comentários

Use o `marshal_context` classe para conversões de dados que exigem um contexto. Para obter mais informações sobre quais conversões exigem um contexto e qual arquivo de marshaling tem a serem incluídos, consulte [visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md). O resultado de marshaling quando você usa um contexto é válido somente até o `marshal_context` objeto é destruído. Para preservar seu resultado, você deve copiar os dados.

O mesmo `marshal_context` pode ser usado para várias conversões de dados. Reutilizar o contexto dessa maneira não afetará os resultados de marshaling de chamadas anteriores.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição| 
|---------|-----------| 
|[marshal_context::marshal_context](#marshal-context)|Constrói um `marshal_context` objeto a ser usado para conversão de dados entre tipos de dados gerenciado e nativo.| 
|[marshal_context::~marshal_context](#tilde-marshal-context)|Destrói um objeto `marshal_context`.| 

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição| 
|---------|-----------| 
|[marshal_context::marshal_as](#marshal-as)|Realiza marshaling em um objeto de dados específico para convertê-lo entre um gerenciado e um tipo de dados nativos.| 


## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >

**Namespace:** msclr::interop

## <a name="marshal-context"></a>marshal_context::marshal_context

Constrói um `marshal_context` objeto a ser usado para conversão de dados entre tipos de dados gerenciado e nativo.

```cpp
marshal_context();
```

### <a name="remarks"></a>Comentários

Algumas conversões de dados exigem um contexto de marshaling. Para obter mais informações sobre quais traduções exigem um contexto e quais marshaling de arquivo que você deve incluir em seu aplicativo, consulte [visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [marshal_context::marshal_as](../dotnet/marshal-context-marshal-as.md).


## <a name="tilde-marshal-context"></a>marshal_context::~marshal_context

Destrói um objeto `marshal_context`.

```cpp
~marshal_context();
```

### <a name="remarks"></a>Comentários

Algumas conversões de dados exigem um contexto de marshaling. Ver [visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais traduções exigem um contexto e qual arquivo marshaling deve ser incluído em seu aplicativo.

Excluindo um `marshal_context` objeto invalidará os dados convertidos pelo contexto. Se você quiser preservar seus dados após um `marshal_context` objeto é destruído, você deve copiar manualmente os dados a uma variável que será mantido.

## <a name="marshal-as"></a>marshal_context::marshal_as

Realiza marshaling em um objeto de dados específico para convertê-lo entre um gerenciado e um tipo de dados nativos.

```cpp
To_Type marshal_as<To_Type>(
   From_Type input
);
```

### <a name="parameters"></a>Parâmetros

*input*<br/>
[in] O valor que você deseja realizar marshaling para um `To_Type` variável.

### <a name="return-value"></a>Valor retornado

Uma variável do tipo `To_Type` que é o valor convertido do `input`.

### <a name="remarks"></a>Comentários

Essa função realiza marshaling em um objeto de dados específico. Use essa função somente com as conversões indicadas pela tabela de [visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md).

Se você tentar realizar marshaling de um par de tipos de dados que não há suporte para `marshal_as` irá gerar um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação. Leia a mensagem fornecida com este erro para obter mais informações. O `C4996` erro pode ser gerado para funções preteridas mais de apenas. Duas condições que geram esse erro estão tentando realizar marshaling de um par de tipos de dados que não têm suporte e tentar usar `marshal_as` para uma conversão que requer um contexto.

A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais, se você precisar de outras conversões. A tabela no `Marshaling Overview in C++` indica qual arquivo marshaling deve ser incluído para cada conversão.

### <a name="example"></a>Exemplo

Este exemplo cria um contexto de marshaling de uma `System::String` para um `const char *` tipo de variável. Os dados convertidos não serão válidos após a linha que exclui o contexto.

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