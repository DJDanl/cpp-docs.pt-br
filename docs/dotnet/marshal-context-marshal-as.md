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
ms.openlocfilehash: 27f27b164d7a00e05e8d080a692f97b696776cbe
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="marshalcontextmarshalas"></a>marshal_context::marshal_as
Realiza marshaling de em um objeto de dados específico para convertê-lo entre um gerenciado e um tipo de dados nativos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
To_Type marshal_as<To_Type>(  
   From_Type input   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `input`  
 O valor que você deseja empacotar um `To_Type` variável.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma variável do tipo `To_Type` que é o valor convertido de `input`.  
  
## <a name="remarks"></a>Comentários  
 Esta função executa a realização de marshaling em um objeto de dados específico. Use esta função somente com as conversões indicadas pela tabela em [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md).  
  
 Se você tentar realizar marshaling de um par de tipos de dados que não são suportados, `marshal_as` irá gerar um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação. Leia a mensagem fornecida com este erro para obter mais informações. O `C4996` erro pode ser gerado para as funções mais de apenas preteridas. Duas condições que geram esse erro estão tentando realizar marshaling de um par de tipos de dados que não são suportados e tentar usar `marshal_as` para uma conversão que requer um contexto.  
  
 A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se você precisa para outras conversões. A tabela `Marshaling Overview in C++` indica qual arquivo marshaling deve ser incluído para cada conversão.  
  
## <a name="example"></a>Exemplo  
 Este exemplo cria um contexto para realizar marshaling de uma `System::String` para um `const char *` tipo de variável. Os dados convertidos não será válidos após a linha que exclui o contexto.  
  
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
 [Visão geral de Marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md)   
 [marshal_as](../dotnet/marshal-as.md)   
 [Classe marshal_context](../dotnet/marshal-context-class.md)