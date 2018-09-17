---
title: marshal_context::marshal_as | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- marshal_context::marshal_as
- marshal_context.marshal_as
- msclr.interop.marshal_context.marshal_as
- msclr::interop::marshal_context::marshal_as
dev_langs:
- C++
helpviewer_keywords:
- marshal_context class [C++], operations
ms.assetid: 24a1afee-51c0-497c-948c-f77fe43635c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f88d086c76ea6b56f1bb049b886df70ceadbdbb9
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707896"
---
# <a name="marshalcontextmarshalas"></a>marshal_context::marshal_as
Realiza marshaling em um objeto de dados específico para convertê-lo entre um gerenciado e um tipo de dados nativos.  
  
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
 Essa função realiza marshaling em um objeto de dados específico. Use essa função somente com as conversões indicadas pela tabela de [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md).  
  
 Se você tentar realizar marshaling de um par de tipos de dados que não são suportados `marshal_as` irá gerar um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação. Leia a mensagem fornecida com este erro para obter mais informações. O `C4996` erro pode ser gerado para funções preteridas mais de apenas. Duas condições que geram esse erro estão tentando realizar marshaling de um par de tipos de dados que não têm suporte e tentar usar `marshal_as` para uma conversão que requer um contexto.  
  
 A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais, se você precisar de outras conversões. A tabela no `Marshaling Overview in C++` indica qual arquivo marshaling deve ser incluído para cada conversão.  
  
## <a name="example"></a>Exemplo  
 Este exemplo cria um contexto de marshaling de uma `System::String` para um `const char *` tipo de variável. Os dados convertidos não será válidos após a linha que exclui o contexto.  
  
```  
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
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >  
  
 **Namespace:** msclr::interop  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)   
 [marshal_as](../dotnet/marshal-as.md)   
 [Classe marshal_context](../dotnet/marshal-context-class.md)