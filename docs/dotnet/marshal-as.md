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
ms.openlocfilehash: 6ab4962f18368f0d896f8b7343baf54e8f59ac52
ms.sourcegitcommit: 0e3da5cea44437c132b5c2ea522bd229ea000a10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/12/2019
ms.locfileid: "70311811"
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
no O valor que você deseja realizar marshaling em `To_Type` uma variável.

## <a name="return-value"></a>Valor de retorno

Uma variável do tipo `To_Type` que é o valor convertido de `input`.

## <a name="remarks"></a>Comentários

Esse método é uma maneira simplificada de converter dados entre tipos nativos e gerenciados. Para determinar quais tipos de dados têm suporte, consulte [visão geral do marshaling no C++ ](../dotnet/overview-of-marshaling-in-cpp.md). Algumas conversões de dados exigem um contexto. Você pode converter esses tipos de dados usando a [classe marshal_context](../dotnet/marshal-context-class.md).

Se você tentar realizar marshaling de um par de tipos de dados que não `marshal_as` têm suporte, o gerará um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) no momento da compilação. Leia a mensagem fornecida com esse erro para obter mais informações. O `C4996` erro pode ser gerado para mais do que apenas funções preteridas. Um exemplo disso é a tentativa de realizar marshaling de um par de tipos de dados que não têm suporte.

A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se precisar de outras conversões. Para ver quais conversões estão associadas a quais arquivos, examine a tabela em `Marshaling Overview`. Independentemente da conversão que você deseja fazer, o requisito de namespace está sempre em vigor.

Gera `System::ArgumentNullException(_EXCEPTION_NULLPTR)` se o parâmetro de entrada é nulo.

## <a name="example"></a>Exemplo

Este exemplo realiza marshaling de `const char*` um para `System::String` um tipo de variável.

```
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

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho:** msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h > ou \<msclr\marshal_atl.h > \<

**Namespace:** msclr:: Interop

## <a name="see-also"></a>Consulte também

[Visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)<br/>
[Classe marshal_context](../dotnet/marshal-context-class.md)
