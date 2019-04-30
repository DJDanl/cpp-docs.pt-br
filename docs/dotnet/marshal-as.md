---
title: marshal_as
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- marshal_as
- msclr.interop.marshal_as
- msclr::interop::marshal_as
helpviewer_keywords:
- marshal_as template [C++]
ms.assetid: 2ed717da-2b11-41e5-981d-47d251771989
ms.openlocfilehash: 2294d8fe94a32f281332c963b21a542366ae3207
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386077"
---
# <a name="marshalas"></a>marshal_as

Esse método converte os dados entre ambientes nativos e gerenciados.

## <a name="syntax"></a>Sintaxe

```
To_Type marshal_as<To_Type>(
   From_Type input
);
```

#### <a name="parameters"></a>Parâmetros

*input*<br/>
[in] O valor que você deseja realizar marshaling para um `To_Type` variável.

## <a name="return-value"></a>Valor de retorno

Uma variável do tipo `To_Type` que é o valor convertido de `input`.

## <a name="remarks"></a>Comentários

Esse método é uma maneira simplificada de converter dados entre tipos nativos e gerenciados. Para determinar quais tipos de dados têm suporte, consulte [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md). Algumas conversões de dados exigem um contexto. Você pode converter esses tipos de dados usando o [classe marshal_context](../dotnet/marshal-context-class.md).

Se você tentar realizar marshaling de um par de tipos de dados que não são suportados `marshal_as` irá gerar um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação. Leia a mensagem fornecida com este erro para obter mais informações. O `C4996` erro pode ser gerado para funções preteridas mais de apenas. Um exemplo disso está tentando realizar marshaling de um par de tipos de dados que não têm suporte.

A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais, se você precisar de outras conversões. Para ver quais conversões são associados a quais arquivos, examine a tabela no `Marshaling Overview`. O requisito de espaço para nome independentemente de quais conversão você deseja fazer, está sempre em vigor.

## <a name="example"></a>Exemplo

Este exemplo realiza marshaling de uma `const char*` para um `System::String` tipo de variável.

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

**Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >

**Namespace:** msclr::interop

## <a name="see-also"></a>Consulte também

[Visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)<br/>
[Classe marshal_context](../dotnet/marshal-context-class.md)
