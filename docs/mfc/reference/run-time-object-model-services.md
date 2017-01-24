---
title: "Servi&#231;os do modelo de objeto de tempo de execu&#231;&#227;o | Microsoft Docs"
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
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macros de serviços do modelo de objeto de tempo de execução"
ms.assetid: 4a3e79df-2ee3-43a4-8193-20298828de85
caps.latest.revision: 15
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servi&#231;os do modelo de objeto de tempo de execu&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes [CObject](../Topic/CObject%20Class.md) e [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) encapsulam vários serviços do objeto, incluindo o acesso às informações da classe de tempo de execução, a serialização, e a criação do objeto dinâmico.  Todas as classes derivadas de `CObject` herdam essa funcionalidade.  
  
 O acesso às informações da classe de tempo de execução permite determinar em tempo de execução informações sobre uma classe do objeto.  A capacidade de determinar a classe de um objeto é em tempo de execução útil quando você precisa da verificação de tipo adicional de argumentos de função e quando você deve escrever o código do objetivo especial com base na classe de um objeto.  As informações da classe de tempo de execução não tem suporte diretamente pela linguagem C\+\+.  
  
 A serialização é o processo de gravação ou leitura do conteúdo de um objeto para ou de um arquivo.  Você pode usar serialização para armazenar o conteúdo de um objeto mesmo depois que o aplicativo.  O objeto pode ser lido do arquivo quando o aplicativo for reiniciado.  Esses objetos de dados que seriam “persistentes.”  
  
 A criação do objeto dinâmico permite criar em tempo de execução um objeto de uma classe especificada.  Por exemplo, o documento, a exibição, e os objetos do quadro devem oferecer suporte à criação dinâmico porque a estrutura exata do criar dinamicamente.  
  
 A tabela a seguir lista as macros MFC que oferecem suporte às informações da classe de tempo de execução, a serialização, e a criação dinâmico.  
  
 Para obter mais informações sobre esses serviços e de serialização do objeto de tempo de execução, consulte o artigo [Classe de CObject: Acessar informações da classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).  
  
### O modelo de objeto de tempo de execução serve a macros  
  
|||  
|-|-|  
|[DECLARE\_DYNAMIC](../Topic/DECLARE_DYNAMIC.md)|Habilita o acesso às informações da classe de tempo de execução \(deve ser usado na declaração de classe\).|  
|[DECLARE\_DYNCREATE](../Topic/DECLARE_DYNCREATE.md)|Permite criação dinâmico e acesso a informações da classe de tempo de execução \(deve ser usado na declaração de classe\).|  
|[DECLARE\_SERIAL](../Topic/DECLARE_SERIAL.md)|Habilita a serialização e o acesso às informações da classe de tempo de execução \(deve ser usado na declaração de classe\).|  
|[IMPLEMENT\_DYNAMIC](../Topic/IMPLEMENT_DYNAMIC.md)|Habilita o acesso às informações da classe de tempo de execução \(deve ser usado na implementação da classe\).|  
|[IMPLEMENT\_DYNCREATE](../Topic/IMPLEMENT_DYNCREATE.md)|Permite criação dinâmico e acesso a informações de tempo de execução \(deve ser usado na implementação da classe\).|  
|[IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md)|Licenças serialização e acesso às informações da classe de tempo de execução \(deve ser usado na implementação da classe\).|  
|[RUNTIME\_CLASS](../Topic/RUNTIME_CLASS.md)|Retorna a estrutura de `CRuntimeClass` que corresponde à classe nomeada.|  
  
 OLE normalmente requer a criação dinâmico de objetos em tempo de execução.  Por exemplo, um aplicativo de servidor OLE deve ser capaz de criar itens dinamicamente com OLE DB em resposta a uma solicitação de um cliente.  De forma similar, um servidor de automação deve ser capaz de criar itens em resposta a solicitações de clientes de automação.  
  
 A biblioteca de classes do Microsoft fornece dois macros específicos ao OLE.  
  
### Criação de objetos OLE dinâmico  
  
|||  
|-|-|  
|[DECLARE\_OLECREATE](../Topic/DECLARE_OLECREATE.md)|Habilita os objetos a serem criados com a automação OLE.|  
|[IMPLEMENT\_OLECREATE](../Topic/IMPLEMENT_OLECREATE.md)|Habilita os objetos a serem criados pelo sistema OLE.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)