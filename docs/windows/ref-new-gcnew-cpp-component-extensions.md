---
title: "REF novo gcnew (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- gcnew
- ref new
- gcnew_cpp
dev_langs:
- C++
helpviewer_keywords:
- ref new keyword (C++)
- gcnew keyword [C++]
ms.assetid: 388a62da-c2df-4a94-a9a2-205b53e577da
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 616117f7274d6f68456aa23614fb354a71982fb2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ref-new-gcnew--c-component-extensions"></a>ref new, gcnew (Extensões de Componentes C++)
O `ref new` palavra-chave agregação aloca uma instância de um tipo que será limpo quando o objeto se torna inacessível e que retorna um identificador ([^](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)) para o objeto alocado.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 Memória para uma instância de um tipo que está alocada por `ref new` é desalocada automaticamente.  
  
 Um `ref new` operação lança `OutOfMemoryException` se não é possível alocar memória.  
  
 Para obter mais informações sobre como a memória para tipos nativos do C++ é alocada e desalocada, consulte [o novo e excluir operadores](../cpp/new-and-delete-operators.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Use `ref new` para alocar memória para objetos de tempo de execução do Windows cujo tempo de vida que você deseja administrar automaticamente. O objeto é desalocado automaticamente quando sua contagem de referência chega a zero, o que ocorre depois que a última cópia da referência estiver fora do escopo. Para obter mais informações, consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 Memória para um tipo gerenciado (tipo de valor ou referência) é alocada por `gcnew`e desalocadas por meio de coleta de lixo.  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo a seguir usa `gcnew` para alocar um objeto de mensagem.  
  
```  
// mcppv2_gcnew_1.cpp  
// compile with: /clr  
ref struct Message {  
   System::String^ sender;  
   System::String^ receiver;  
   System::String^ data;  
};  
  
int main() {  
   Message^ h_Message  = gcnew Message;  
  //...  
}  
```  
  
 **Exemplo**  
  
 O exemplo a seguir usa `gcnew` para criar um tipo de valor demarcado para uso como um tipo de referência.  
  
```  
// example2.cpp : main project file.  
// compile with /clr  
using namespace System;  
value class Boxed {  
    public:  
        int i;  
};  
int main()  
{  
    Boxed^ y = gcnew Boxed;  
    y->i = 32;  
    Console::WriteLine(y->i);  
    return 0;  
}  
```  
  
 **Saída**  
  
```Output  
32  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)