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
ms.openlocfilehash: 110fe4abf7eb90b05e7feef563efa4882bed0fc6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332007"
---
# <a name="marshal_context-class"></a>Classe marshal_context

Essa classe converte dados entre ambientes nativos e gerenciados.

## <a name="syntax"></a>Sintaxe

```cpp
class marshal_context
```

## <a name="remarks"></a>Comentários

Use `marshal_context` a classe para conversões de dados que requerem um contexto. Para obter mais informações sobre quais conversões requerem um contexto e quais arquivos de marshaling devem ser incluídos, consulte [Visão geral do marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md). O resultado do marshaling quando você usa `marshal_context` um contexto é válido apenas até que o objeto seja destruído. Para preservar seu resultado, você deve copiar os dados.

O `marshal_context` mesmo pode ser usado para inúmeras conversões de dados. Reutilizar o contexto desta maneira não afetará os resultados de chamadas de marshaling anteriores.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|---------|-----------|
|[marshal_context::marshal_context](#marshal-context)|Constrói um `marshal_context` objeto para usar para conversão de dados entre tipos de dados gerenciados e nativos.|
|[marshal_context::~marshal_context](#tilde-marshal-context)|Destrói um objeto `marshal_context`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[marshal_context::marshal_as](#marshal-as)|Executa o marshaling em um objeto de dados específico para convertê-lo entre um tipo de dados gerenciado e um tipo de dados nativo.|

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho:** \<msclr\marshal.h>, \<msclr\marshal_windows.h>, \<msclr\marshal_cppstd.h> ou \<msclr\marshal_atl.h>

**Namespace:** msclr::interop

## <a name="marshal_contextmarshal_context"></a><a name="marshal-context"></a>marshal_context:marshal_context

Constrói um `marshal_context` objeto para usar para conversão de dados entre tipos de dados gerenciados e nativos.

```cpp
marshal_context();
```

### <a name="remarks"></a>Comentários

Algumas conversões de dados requerem um contexto federal. Para obter mais informações sobre quais traduções requerem um contexto e qual arquivo de marshaling você deve incluir em seu aplicativo, consulte [Visão geral do marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md).

### <a name="example"></a>Exemplo

Veja o exemplo [de marshal_context::marshal_as](../dotnet/marshal-context-marshal-as.md).

## <a name="marshal_contextmarshal_context"></a><a name="tilde-marshal-context"></a>marshal_context::~marshal_context

Destrói um objeto `marshal_context`.

```cpp
~marshal_context();
```

### <a name="remarks"></a>Comentários

Algumas conversões de dados requerem um contexto federal. Consulte [visão geral do marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais traduções requerem um contexto e qual arquivo de marshaling deve ser incluído em seu aplicativo.

A exclusão de um `marshal_context` objeto invalidará os dados convertidos por esse contexto. Se você quiser preservar seus `marshal_context` dados depois que um objeto for destruído, você deve copiar manualmente os dados para uma variável que persistirá.

## <a name="marshal_contextmarshal_as"></a><a name="marshal-as"></a>marshal_context:marshal_as

Executa o marshaling em um objeto de dados específico para convertê-lo entre um tipo de dados gerenciado e um tipo de dados nativo.

```cpp
To_Type marshal_as<To_Type>(
   From_Type input
);
```

### <a name="parameters"></a>Parâmetros

*Entrada*<br/>
[em] O valor que você quer `To_Type` marechal para uma variável.

### <a name="return-value"></a>Valor retornado

Uma variável `To_Type` do tipo que é `input`o valor convertido de .

### <a name="remarks"></a>Comentários

Esta função executa o empacotamento em um objeto de dados específico. Use esta função apenas com as conversões indicadas pela tabela em [Visão Geral do marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md).

Se você tentar empacotar um par de `marshal_as` tipos de dados que não são suportados, gerará um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) na hora da compilação. Leia a mensagem fornecida com este erro para obter mais informações. O `C4996` erro pode ser gerado para mais do que apenas funções depreciadas. Duas condições que geram esse erro são tentar empacotar um par `marshal_as` de tipos de dados que não são suportados e tentar usar para uma conversão que requer um contexto.

A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se precisar para outras conversões. A tabela `Marshaling Overview in C++` em indica qual arquivo de marshaling deve ser incluído para cada conversão.

### <a name="example"></a>Exemplo

Este exemplo cria um contexto `System::String` para `const char *` empacotar de um para um tipo variável. Os dados convertidos não serão válidos após a linha que exclui o contexto.

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
