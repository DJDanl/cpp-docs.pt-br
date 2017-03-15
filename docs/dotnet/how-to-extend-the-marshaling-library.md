---
title: "Como estender a biblioteca de marshaling | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Realizando Marshaling em Biblioteca, estendendo"
ms.assetid: 4c4a56d7-1d44-4118-b85f-f9686515e6e9
caps.latest.revision: 27
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como estender a biblioteca de marshaling
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como estender a biblioteca marshaling para fornecer mais conversões entre tipos de dados.  Os usuários podem estender a biblioteca marshaling para todas as conversões de dados com suporte não atualmente pela biblioteca.  
  
 Você pode estender a biblioteca marshaling de uma de duas maneiras \- com ou sem [Classe marshal\_context](../dotnet/marshal-context-class.md).  Examine o tópico de [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md) para determinar se uma nova conversão requer um contexto.  
  
 Em ambos os casos, você cria primeiro um arquivo para novos conversões marshaling.  Você faz isso para preservar a integridade dos arquivos de biblioteca marshaling padrão.  Se você quiser mover um projeto para outro computador ou a outro programador, você deve copiar o novo arquivo marshaling junto com o restante do projeto.  Assim, o usuário que recebe o projeto será garantida para receber novas conversões e não precisará modificar os arquivos de biblioteca.  
  
### Para estender a biblioteca Marshaling com uma conversão que não requer um contexto  
  
1.  Crie um arquivo para armazenar as novas funções marshaling, por exemplo, MyMarshal.h.  
  
2.  Contém um ou mais dos arquivos de biblioteca de marshaling:  
  
    -   marshal.h para tipos de base.  
  
    -   marshal\_windows.h para tipos de dados do windows.  
  
    -   marshal\_cppstd.h para tipos de dados STL.  
  
    -   marshal\_atl.h para tipos de dados de ATL.  
  
3.  Use o código na extremidade dessas etapas para gravar a função de conversão.  Neste código, EXCEPT é o tipo para converter em, FROM é o tipo à conversão de, e `from` é o parâmetro a ser convertido.  
  
4.  Substitua o comentário sobre a lógica de conversão com o código para converter o parâmetro de `from` em um objeto de digitar o e para retornar o objeto convertido.  
  
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
  
### Para estender a biblioteca Marshaling com uma conversão que requer um contexto  
  
1.  Crie um arquivo para armazenar as novas funções marshaling, por exemplo, MyMarshal.h  
  
2.  Contém um ou mais dos arquivos de biblioteca de marshaling:  
  
    -   marshal.h para tipos de base.  
  
    -   marshal\_windows.h para tipos de dados do windows.  
  
    -   marshal\_cppstd.h para tipos de dados STL.  
  
    -   marshal\_atl.h para tipos de dados de ATL.  
  
3.  Use o código na extremidade dessas etapas para gravar a função de conversão.  Neste código, EXCEPT é o tipo para converter em, FROM é o tipo à conversão de, `toObject` é um ponteiro na qual armazenar o resultado e, em `fromObject` é o parâmetro a ser convertido.  
  
4.  Substitua o comentário sobre inicializar com o código para inicializar `toPtr` para o apropriado vazia o valor.  Por exemplo, se é um ponteiro, defina\-o como `NULL`.  
  
5.  Substitua o comentário sobre a lógica de conversão com o código para converter o parâmetro de `from` em um objeto de tipo de *TO* .  Esse objeto convertido será armazenado em `toPtr`.  
  
6.  Substitua o comentário sobre como definir `toObject` com o código para definir `toObject` ao objeto convertido.  
  
7.  Substitua o comentário sobre limpar recursos nativos com o código para liberar toda a memória alocada por `toPtr`.  Se `toPtr` alocou a memória usando `new`, use `delete` para liberar a memória.  
  
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
  
## Exemplo  
 O exemplo a seguir estende a biblioteca marshaling com uma conversão que não requer um contexto.  Neste exemplo, o código a seguir converte a informações de funcionários de um tipo de dados nativo para um tipo de dados gerenciados.  
  
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
  
 No exemplo anterior, a função de `marshal_as` retorna um identificador para os dados convertidos.  Isso é feito para evitar a criação de uma cópia adicional dos dados.  Retornar a variável diretamente teria um custo de desempenho desnecessário associado a ela.  
  
  **Nome gerenciada: Jeff Smith**  
**Endereço gerenciada: 123 Main street**  
**Código postal gerenciada: 98111**   
## Exemplo  
 O exemplo a seguir converte informações de funcionários de um tipo de dados gerenciado em um tipo de dados nativo.  Essa conversão requer um contexto marshaling.  
  
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
  
  **Nome nativo: Jeff Smith**  
**Endereço nativo: 123 Main street**  
**Código postal nativo: 98111**   
## Consulte também  
 [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md)