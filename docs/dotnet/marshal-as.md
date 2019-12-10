---
title: marshal_as
ms.date: 07/12/2019
ms.topic: reference
f1_keywords:
- marshal_as
- msclr.interop.marshal_as
- msclr::interop::marshal_as
helpviewer_keywords:
- marshal_as template [C++]
ms.assetid: 2ed717da-2b11-41e5-981d-47d251771989
ms.openlocfilehash: 2b2cacb0acf04aa40b3e299bffd7357e04916b16
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988133"
---
# <a name="marshal_as"></a>marshal_as

Esse método converte dados entre ambientes nativos e gerenciados.

## <a name="syntax"></a>Sintaxe

```
To_Type marshal_as<To_Type>(
   From_Type input
);
```

#### <a name="parameters"></a>Parâmetros

*input*<br/>
no O valor que você deseja realizar marshaling em uma variável `To_Type`.

## <a name="return-value"></a>Valor retornado

Uma variável do tipo `To_Type` que é o valor convertido de `input`.

## <a name="remarks"></a>Comentários

Esse método é uma maneira simplificada de converter dados entre tipos nativos e gerenciados. Para determinar quais tipos de dados têm suporte, consulte [visão geral do marshaling no C++ ](../dotnet/overview-of-marshaling-in-cpp.md). Algumas conversões de dados exigem um contexto. Você pode converter esses tipos de dados usando a [classe marshal_context](../dotnet/marshal-context-class.md).

Se você tentar realizar marshaling de um par de tipos de dados que não têm suporte, `marshal_as` gerará um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) no momento da compilação. Leia a mensagem fornecida com esse erro para obter mais informações. O erro de `C4996` pode ser gerado para mais do que apenas funções preteridas. Um exemplo disso é a tentativa de realizar marshaling de um par de tipos de dados que não têm suporte.

A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se precisar de outras conversões. Para ver quais conversões estão associadas a quais arquivos, procure na tabela em `Marshaling Overview`. Independentemente da conversão que você deseja fazer, o requisito de namespace está sempre em vigor.

Gera `System::ArgumentNullException(_EXCEPTION_NULLPTR)` se o parâmetro de entrada é nulo.

## <a name="example"></a>Exemplo

Este exemplo realiza marshaling de um `const char*` para um tipo de variável `System::String`.

```cpp
// marshal_as_test.cpp
// compile with: /clr
#include <stdlib.h>
#include <string.h>
#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;

int main() {
   const char* message = "Test String to Marshal";
   String^ result;
   result = marshal_as<String^>( message );
   return 0;
}
```

## <a name="requirements"></a>Requisitos do

**Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr \ marshal_windows. h >, \<msclr \ marshal_cppstd. h > ou \<msclr \ marshal_atl. h >

**Namespace:** msclr:: Interop

## <a name="see-also"></a>Consulte também

[Visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)<br/>
[Classe marshal_context](../dotnet/marshal-context-class.md)
