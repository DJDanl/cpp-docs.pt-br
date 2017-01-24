---
title: "Classe de CMetaFileDC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMetaFileDC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMetaFileDC"
  - "gráficos, implementando"
  - "Metarquivos do Windows [C++]"
ms.assetid: ffce60fa-4181-4d46-9832-25e46fad4db4
caps.latest.revision: 23
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMetaFileDC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa meta\-arquivo do windows, que contém uma seqüência de elementos gráficos interface de dispositivo que \(GDI\) comandos que você pode repetir criar uma imagem ou texto desejado.  
  
## Sintaxe  
  
```  
class CMetaFileDC : public CDC  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMetaFileDC::CMetaFileDC](../Topic/CMetaFileDC::CMetaFileDC.md)|Constrói um objeto de `CMetaFileDC` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMetaFileDC::Close](../Topic/CMetaFileDC::Close.md)|Fecha o contexto de dispositivo e cria uma alça de metarquivo.|  
|[CMetaFileDC::CloseEnhanced](../Topic/CMetaFileDC::CloseEnhanced.md)|Fecha um contexto do dispositivo de aprimorar\- metarquivo e cria uma alça de aprimorar\- metarquivo.|  
|[CMetaFileDC::Create](../Topic/CMetaFileDC::Create.md)|Cria o contexto do dispositivo de metarquivo do windows e anexá\-la ao objeto de `CMetaFileDC` .|  
|[CMetaFileDC::CreateEnhanced](../Topic/CMetaFileDC::CreateEnhanced.md)|Cria um contexto do dispositivo de metarquivo para meta\-arquivo de aprimorar\- formato.|  
  
## Comentários  
 Para implementar meta\-arquivo do windows, primeiro crie um objeto de `CMetaFileDC` .  Chamar o construtor de `CMetaFileDC` , então chamar a função de membro de [Criar](../Topic/CMetaFileDC::Create.md) , que cria um contexto do dispositivo de metarquivo do windows e anexa o ao objeto de `CMetaFileDC` .  
  
 O exemplo a seguir enviar o objeto de `CMetaFileDC` a seqüência de `CDC` GDI comandos que você pretende para ele a repetição.  Somente os comandos do GDI que criam saída, como `MoveTo` e `LineTo`, podem ser usados.  
  
 Após você ter enviado os comandos desejado ao metarquivo, chame a função de membro de **Fechar** , que fecha os contextos de dispositivo de metarquivo e retorna uma alça de metarquivo.  Descarte no objeto de `CMetaFileDC` .  
  
 [CDC::PlayMetaFile](../Topic/CDC::PlayMetaFile.md) pode usar a alça de metarquivo para executar repetidamente. o metarquivo  O metarquivo também pode ser manipulado por funções do windows como [CopyMetaFile](http://msdn.microsoft.com/library/windows/desktop/dd183480), que copia meta\-arquivo no disco.  
  
 Quando o metarquivo não for mais necessário, exclua\-o de memória com a função do windows de [DeleteMetaFile](http://msdn.microsoft.com/library/windows/desktop/dd183537) .  
  
 Você também pode implementar o objeto de `CMetaFileDC` de modo que pode manipular chamadas de saída e atribuir chamadas de GDI como `GetTextExtent`.  Tal metarquivo é mais flexível e pode facilmente reutilizar o código geral do GDI, que geralmente consiste em uma mistura de saída e o atributo chama.  A classe de `CMetaFileDC` herda dois contextos de dispositivo, `m_hDC` e `m_hAttribDC`, de `CDC`.  O contexto do dispositivo de `m_hDC` trata todas as chamadas de saída de [CDC](../Topic/CDC%20Class.md) GDI e o contexto do dispositivo de `m_hAttribDC` todas as chamadas de atributo de `CDC` GDI.  Normalmente, esses dois contextos de dispositivos referem\-se ao mesmo dispositivo.  Em o caso de `CMetaFileDC`, dc. do atributo é definida como **NULO** por padrão.  
  
 Crie um segundo contexto de dispositivo que aponta para a tela, em uma impressora, ou para o dispositivo que não seja meta\-arquivo, então chamar a função de membro de `SetAttribDC` para associar o novo contexto de dispositivo com `m_hAttribDC`.  Chamadas de GDI para informações serão direcionados agora a nova `m_hAttribDC`.  Chamadas de saída GDI irã0 a `m_hDC`, que representa o metarquivo.  
  
 Para obter mais informações sobre `CMetaFileDC`, consulte [Contextos de dispositivo](../Topic/Device%20Contexts.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDC](../Topic/CDC%20Class.md)  
  
 `CMetaFileDC`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [CDC Class](../Topic/CDC%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)