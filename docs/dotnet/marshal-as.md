---
title: marshal_as | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- marshal_as
- msclr.interop.marshal_as
- msclr::interop::marshal_as
dev_langs:
- C++
helpviewer_keywords:
- marshal_as template [C++]
ms.assetid: 2ed717da-2b11-41e5-981d-47d251771989
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ebca4a94fa48feb4ff5fb897293303a395ac4eb8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="marshalas"></a>marshal_as
Este método converte dados entre ambientes gerenciados e nativos.  
  
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
 Esse método é uma maneira simplificada para converter os dados entre os tipos nativos e gerenciados. Para determinar quais tipos de dados têm suporte, consulte [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md). Algumas conversões de dados exigem um contexto. Você pode converter esses tipos de dados usando o [classe marshal_context](../dotnet/marshal-context-class.md).  
  
 Se você tentar realizar marshaling de um par de tipos de dados que não são suportados, `marshal_as` irá gerar um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação. Leia a mensagem fornecida com este erro para obter mais informações. O `C4996` erro pode ser gerado para as funções mais de apenas preteridas. Um exemplo disso é tentar realizar marshaling de um par de tipos de dados que não são suportados.  
  
 A biblioteca de marshaling consiste em vários arquivos de cabeçalho. Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se você precisa para outras conversões. Para ver quais conversões estão associados com os arquivos, veja na tabela `Marshaling Overview`. O requisito de espaço para nome independentemente de qual conversão você deseja fazer, está sempre em vigor.  
  
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
 [Visão geral de Marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md)   
 [Classe marshal_context](../dotnet/marshal-context-class.md)