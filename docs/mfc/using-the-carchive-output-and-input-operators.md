---
title: "Usando os operadores CArchive &lt;&lt; and &gt;&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CArchive"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CArchive, operadores"
  - "Classe CArchive, armazenando e carregando objetos"
  - "objetos [C++], carregando a partir dos valores armazenados anteriormente"
ms.assetid: 56aef326-02dc-4992-8282-f0a4b78a064e
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando os operadores CArchive &lt;&lt; and &gt;&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`CArchive` fornece \<\< e \>\> operadores para ler e gravar tipos de dados simples assim como `CObject`s para e de um arquivo.  
  
#### Para armazenar um objeto em um arquivo por meio de um arquivo morto  
  
1.  O exemplo a seguir mostra como armazenar um objeto em um arquivo por meio de um arquivo morto:  
  
     [!code-cpp[NVC_MFCSerialization#7](../mfc/codesnippet/CPP/using-the-carchive-output-and-input-operators_1.cpp)]  
  
#### Para carregar um objeto de um valor armazenado anteriormente em um arquivo  
  
1.  O exemplo a seguir mostra como carregar um objeto de um valor armazenado anteriormente em um arquivo:  
  
     [!code-cpp[NVC_MFCSerialization#8](../mfc/codesnippet/CPP/using-the-carchive-output-and-input-operators_2.cpp)]  
  
 Geralmente, você armazena e carregar dados para e de um arquivo por meio de um arquivo morto em funções de `CObject`\- classes derivadas de `Serialize` , que deve ter declarado com a macro de **DECLARE\_SERIALIZE** .  Uma referência a um objeto de `CArchive` é transmitida à função de `Serialize` .  Você chama a função de `IsLoading` do objeto de `CArchive` para determinar se a função de `Serialize` esteve chamada para carregar dados de um arquivo ou do repositório para o arquivo.  
  
 A função de `Serialize` de `CObject`serializável \- a classe derivada geralmente tem o seguinte formato:  
  
 [!code-cpp[NVC_MFCSerialization#9](../mfc/codesnippet/CPP/using-the-carchive-output-and-input-operators_3.cpp)]  
  
 O modelo acima do código é exatamente igual ao AppWizard cria para a função de `Serialize` do documento \(se uma classe derivada de **CDocument\)**.  Ajuda desse modelo de código você escreve o código que é mais fácil de revisão, porque o código para armazenar e o código de carga devem estar sempre paralelos, como no exemplo a seguir:  
  
 [!code-cpp[NVC_MFCSerialization#10](../mfc/codesnippet/CPP/using-the-carchive-output-and-input-operators_4.cpp)]  
  
 A biblioteca define **\<\<** e os operadores de **\>\>** para `CArchive` como o primeiro operando e os seguintes tipos de dados e a classe digite como o segundo operando:  
  
||||  
|-|-|-|  
|`CObject*`|**SIZE e CSize**|**float**|  
|**WORD**|`CString`|**POINT** e `CPoint`|  
|`DWORD`|**BYTE**|`RECT` e `CRect`|  
|**Double**|**LONG**|`CTime` e `CTimeSpan`|  
|`Int`|**COleCurrency**|`COleVariant`|  
|`COleDateTime`|`COleDateTimeSpan`||  
  
> [!NOTE]
>  Armazenar e carregar `CObject`s meio de um arquivo morto exigem consideração adicional.  Para obter mais informações, consulte [Armazenando e carregamento CObjects meio de um arquivo morto](../Topic/Storing%20and%20Loading%20CObjects%20via%20an%20Archive.md).  
  
 Os operadores de **CArchive \<\<** e de **\>\>** sempre retornam uma referência ao objeto de `CArchive` , que é o primeiro operando.  Isso permite que o encadeamento os operadores, como ilustrado abaixo:  
  
 [!code-cpp[NVC_MFCSerialization#11](../mfc/codesnippet/CPP/using-the-carchive-output-and-input-operators_5.cpp)]  
  
## Consulte também  
 [Serialização: serializando um objeto](../Topic/Serialization:%20Serializing%20an%20Object.md)