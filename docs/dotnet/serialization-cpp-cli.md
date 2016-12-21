---
title: "Serializa&#231;&#227;o (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".NET Framework [C++], serialização"
  - "código gerenciado [C++], serializando"
  - "Classe NonSerializedAttribute, aplicativos gerenciados"
  - "Classe SerializableAttribute, aplicativos gerenciados"
  - "serialização [C++]"
  - "serialização [C++], sobre serialização"
ms.assetid: 869010ca-74e1-4989-b409-4643cdb94084
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Serializa&#231;&#227;o (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A serialização \(o processo de armazenar o estado de um objeto ou membro a uma mídia permanente\) de classes gerenciadas \(inclusive campos individuais ou propriedades\) tem suporte da classes de <xref:System.SerializableAttribute> e de <xref:System.NonSerializedAttribute> .  
  
## Comentários  
 Aplique o atributo personalizado de **SerializableAttribute** a uma classe gerenciada para serializar a classe inteira ou para aplicar somente aos campos ou propriedades específicas para serializar partes da classe gerenciada.  Use o atributo personalizado de **NonSerializedAttribute** para isentar campos ou propriedades de uma classe gerenciada de ser serializado.  
  
## Exemplo  
  
### Descrição  
 No exemplo a seguir, a classe `MyClass` \(e a propriedade `m_nCount`\) são marcadas como serializáveis.  No entanto, a propriedade de `m_nData` não é serializada conforme indicado pelo atributo personalizado de **NonSerialized** :  
  
### Código  
  
```  
// serialization_and_mcpp.cpp  
// compile with: /LD /clr  
using namespace System;  
  
[ Serializable ]  
public ref class MyClass {  
public:  
   int m_nCount;  
private:  
   [ NonSerialized ]  
   int m_nData;  
};  
```  
  
### Comentários  
 Observe que os dois atributos podem ser referenciados usando seu nome curto “” \(**Serializável** e **NonSerialized**\).  Isso é explicado mais em [Aplicando atributos](../Topic/Applying%20Attributes.md).  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)