---
title: "Aviso do compilador (n&#237;vel 1) C4462 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4462"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4462"
ms.assetid: 4e20aca4-293e-4c75-a83d-961c27ab7840
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4462
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não é possível determinar o GUID do tipo.O programa poderá falhar no tempo de execução.  
  
 O aviso C4462 ocorre em um aplicativo ou um componente do Tempo de Execução do Windows quando um `TypedEventHandler` público tem como um de seus parâmetros de tipo uma referência para a classe do delimitador.  
  
 **Esse tipo de código gera o aviso:**  
  
```  
namespace N  
{  
       public ref struct EventArgs sealed {};  
       public ref struct R sealed  
       {  
              R() {}  
              event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;  
       };  
}  
  
[Platform::MTAThread]  
int main()  
{  
     auto x = ref new N::R();  
}  
  
```  
  
 **Para corrigir o erro:**  
  
 Existem duas maneiras de resolver o erro.  Uma maneira, mostrada no exemplo a seguir, é dar ao evento a acessibilidade interna para que ele esteja disponível para codificar no mesmo executável, mas não para codificar em outros componentes do Tempo de Execução do Windows.  
  
```  
  
internal:  
event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;  
  
```  
  
 Se o evento deve ser público, você pode usar outra solução alternativa, que é expor o evento por meio de uma interface padrão:  
  
```  
  
ref struct R;  
public interface struct IR { event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e; };  
  
public ref struct R sealed : [Windows::Foundation::Metadata::Default] IR  
{  
    R() {}  
    virtual event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;  
};  
  
```  
  
 O GUID do tipo `Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^` só é usado quando o tipo é acessado de outro componente.  A primeira solução alternativa funciona porque só pode ser acessada em seu próprio componente após a solução.  Caso contrário, o compilador precisa presumir o pior caso e emitir o aviso.