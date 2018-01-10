---
title: 'Como: estender a biblioteca de Marshaling | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords: Marshaling Library, extending
ms.assetid: 4c4a56d7-1d44-4118-b85f-f9686515e6e9
caps.latest.revision: "27"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ee919e1faa37959d25e8e42581c8cde80d640337
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-extend-the-marshaling-library"></a>Como estender a biblioteca de marshaling
Este tópico explica como estender a biblioteca de marshaling para fornecer mais conversões entre tipos de dados. Os usuários podem estender a biblioteca de marshaling para qualquer conversões de dados sem suporte no momento da biblioteca.  
  
 Você pode estender a biblioteca de marshaling de uma das duas maneiras - com ou sem um [classe marshal_context](../dotnet/marshal-context-class.md). Examine o [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) tópico para determinar se uma nova conversão requer um contexto.  
  
 Em ambos os casos, você primeiro crie um arquivo para conversões de marshaling de novo. Faça isso para preservar a integridade dos arquivos de biblioteca de marshaling padrão. Se você quiser um projeto para outro computador ou para outro programador de porta, você deve copiar o arquivo de marshaling novo junto com o restante do projeto. Dessa maneira, o usuário que recebe o projeto será garantido para receber as conversões de novo e não será necessário modificar os arquivos de biblioteca.  
  
### <a name="to-extend-the-marshaling-library-with-a-conversion-that-does-not-require-a-context"></a>Para estender a biblioteca de Marshaling de uma conversão que não requer um contexto  
  
1.  Crie um arquivo para armazenar as novas funções de empacotamento, por exemplo, MyMarshal.h.  
  
2.  Inclua um ou mais dos arquivos de biblioteca de marshaling:  
  
    -   Marshal.h para tipos de base.  
  
    -   marshal_windows.h para tipos de dados do windows.  
  
    -   marshal_cppstd.h para tipos de dados de biblioteca padrão C++.  
  
    -   marshal_atl.h ATL para tipos de dados.  
  
3.  Use o código no final dessas etapas para gravar a função de conversão. Nesse código, para o tipo para converter, FROM é o tipo para converter de, e `from` é o parâmetro a ser convertido.  
  
4.  Substitua o comentário sobre a lógica de conversão com o código para converter o `from` parâmetro em um objeto de TO tipo e retornam o objeto convertido.  
  
```  
namespace msclr {  
   namespace interop {  
      template<>  
      inline TO marshal_as<TO, FROM> (const FROM& from) {  
         // Insert conversion logic here, and return a TO parameter.  
      }  
   }  
}  
```  
  
### <a name="to-extend-the-marshaling-library-with-a-conversion-that-requires-a-context"></a>Para estender a biblioteca de Marshaling com uma conversão que requer um contexto  
  
1.  Criar um arquivo para armazenar as novas funções de empacotamento, por exemplo, MyMarshal.h  
  
2.  Inclua um ou mais dos arquivos de biblioteca de marshaling:  
  
    -   Marshal.h para tipos de base.  
  
    -   marshal_windows.h para tipos de dados do windows.  
  
    -   marshal_cppstd.h para tipos de dados de biblioteca padrão C++.  
  
    -   marshal_atl.h ATL para tipos de dados.  
  
3.  Use o código no final dessas etapas para gravar a função de conversão. Nesse código, para o tipo para converter, FROM é o tipo para converter de, `toObject` é um ponteiro para armazenar o resultado e `fromObject` é o parâmetro a ser convertido.  
  
4.  Substitua o comentário sobre a inicialização com o código para inicializar o `toPtr` para o valor vazio apropriado. Por exemplo, se for um ponteiro, defina-o `NULL`.  
  
5.  Substitua o comentário sobre a lógica de conversão com o código para converter o `from` parâmetro em um objeto de *TO* tipo. Este objeto convertido será armazenado no `toPtr`.  
  
6.  Substitua o comentário sobre a configuração de `toObject` com o código para definir `toObject` para seu objeto convertido.  
  
7.  Substitua o comentário sobre limpeza de recursos nativos com o código para liberar a memória alocada por qualquer `toPtr`. Se `toPtr` memória alocada usando `new`, use `delete` para liberar a memória.  
  
```  
namespace msclr {  
   namespace interop {  
      template<>  
      ref class context_node<TO, FROM> : public context_node_base  
      {  
      private:  
         TO toPtr;  
      public:  
         context_node(TO& toObject, FROM fromObject)  
         {  
            // (Step 4) Initialize toPtr to the appropriate empty value.  
            // (Step 5) Insert conversion logic here.  
            // (Step 6) Set toObject to the converted parameter.  
         }  
         ~context_node()  
         {  
            this->!context_node();  
         }  
      protected:  
         !context_node()  
         {  
            // (Step 7) Clean up native resources.  
         }  
      };  
   }  
}   
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir estende a biblioteca de marshaling com uma conversão que não requer um contexto. Neste exemplo, o código converte as informações de funcionário de um tipo de dados nativo para um tipo de dados gerenciado.  
  
```  
// MyMarshalNoContext.cpp  
// compile with: /clr  
#include <msclr/marshal.h>  
  
value struct ManagedEmp {  
   System::String^ name;  
   System::String^ address;  
   int zipCode;  
};  
  
struct NativeEmp {  
   char* name;  
   char* address;  
   int zipCode;  
};  
  
namespace msclr {  
   namespace interop {  
      template<>  
      inline ManagedEmp^ marshal_as<ManagedEmp^, NativeEmp> (const NativeEmp& from) {  
         ManagedEmp^ toValue = gcnew ManagedEmp;  
         toValue->name = marshal_as<System::String^>(from.name);  
         toValue->address = marshal_as<System::String^>(from.address);  
         toValue->zipCode = from.zipCode;  
         return toValue;  
      }  
   }  
}  
  
using namespace System;  
using namespace msclr::interop;  
  
int main() {   
   NativeEmp employee;  
  
   employee.name = "Jeff Smith";  
   employee.address = "123 Main Street";  
   employee.zipCode = 98111;  
  
   ManagedEmp^ result = marshal_as<ManagedEmp^>(employee);  
  
   Console::WriteLine("Managed name: {0}", result->name);  
   Console::WriteLine("Managed address: {0}", result->address);  
   Console::WriteLine("Managed zip code: {0}", result->zipCode);  
  
   return 0;  
}  
```  
  
 No exemplo anterior, o `marshal_as` função retorna um identificador para os dados convertidos. Isso foi feito para evitar a criação de uma cópia adicional dos dados. Retornando a variável diretamente seria um custo de desempenho desnecessários associou com ele.  
  
```Output  
Managed name: Jeff Smith  
Managed address: 123 Main Street  
Managed zip code: 98111  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir converte as informações de funcionário de um tipo de dados gerenciados em um tipo de dados nativos. Essa conversão requer um contexto de marshaling.  
  
```  
// MyMarshalContext.cpp  
// compile with: /clr  
#include <stdlib.h>  
#include <string.h>  
#include <msclr/marshal.h>  
  
value struct ManagedEmp {  
   System::String^ name;  
   System::String^ address;  
   int zipCode;  
};  
  
struct NativeEmp {  
   const char* name;  
   const char* address;  
   int zipCode;  
};  
  
namespace msclr {  
   namespace interop {  
      template<>  
      ref class context_node<NativeEmp*, ManagedEmp^> : public context_node_base  
      {  
      private:  
         NativeEmp* toPtr;  
         marshal_context context;  
      public:  
         context_node(NativeEmp*& toObject, ManagedEmp^ fromObject)  
         {  
            // Conversion logic starts here  
            toPtr = NULL;  
  
            const char* nativeName;  
            const char* nativeAddress;  
  
            // Convert the name from String^ to const char*.  
            System::String^ tempValue = fromObject->name;  
            nativeName = context.marshal_as<const char*>(tempValue);  
  
            // Convert the address from String^ to const char*.  
            tempValue = fromObject->address;  
            nativeAddress = context.marshal_as<const char*>(tempValue);  
  
            toPtr = new NativeEmp();  
            toPtr->name = nativeName;  
            toPtr->address = nativeAddress;  
            toPtr->zipCode = fromObject->zipCode;  
  
            toObject = toPtr;  
         }  
         ~context_node()  
         {  
            this->!context_node();  
         }  
      protected:  
         !context_node()  
         {  
            // When the context is deleted, it will free the memory  
            // allocated for toPtr->name and toPtr->address, so toPtr  
            // is the only memory that needs to be freed.  
            if (toPtr != NULL) {  
               delete toPtr;  
               toPtr = NULL;  
            }  
         }  
      };  
   }  
}   
  
using namespace System;  
using namespace msclr::interop;  
  
int main() {  
   ManagedEmp^ employee = gcnew ManagedEmp();  
  
   employee->name = gcnew String("Jeff Smith");  
   employee->address = gcnew String("123 Main Street");  
   employee->zipCode = 98111;  
  
   marshal_context context;  
   NativeEmp* result = context.marshal_as<NativeEmp*>(employee);  
  
   if (result != NULL) {  
      printf_s("Native name: %s\nNative address: %s\nNative zip code: %d\n",  
         result->name, result->address, result->zipCode);  
   }  
  
   return 0;  
}  
```  
  
```Output  
Native name: Jeff Smith  
Native address: 123 Main Street  
Native zip code: 98111  
```  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)