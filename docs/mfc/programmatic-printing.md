---
title: "Impress&#227;o program&#225;tica | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "documentos ativos [C++], imprimindo"
  - "Interface IPrint"
  - "imprimindo [MFC]"
  - "imprimindo [MFC], documentos ativos"
  - "imprimindo [MFC], programático"
ms.assetid: 3db0945b-5e13-4be4-86a0-6aecdae565bd
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Impress&#227;o program&#225;tica
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

OLE que significa identificar documentos persistentes \(**GetClassFile**\) e carregá\-los em seu código associado \(`CoCreateInstance`, **QueryInterface\(IID\_IPersistFile\)**, **QueryInterface\(IID\_IPersistStorage\)**, **IPersistFile::Load**, e **IPersistStorage::Load**\).  Para habilitar mais documentos de impressão, a retenção ativa do documento \(que usa um design OLE existente não enviado originalmente com OLE 2,0\) apresenta uma interface de impressão de base padrão, `IPrint`, normalmente \- disponíveis em qualquer objeto que possa carregar o estado persistente de tipo de documento.  Cada exibição de um documento ativo pode opcionalmente oferecer suporte à interface de **IPrint** para fornecer esses recursos.  
  
 A interface de `IPrint` é definida da seguinte maneira:  
  
 `interface IPrint : IUnknown`  
  
 `{`  
  
 `HRESULT SetInitialPageNum([in] LONG nFirstPage);`  
  
 `HRESULT GetPageInfo(`  
  
 `[out] LONG *pnFirstPage,`  
  
 `[out] LONG *pcPages);`  
  
 `HRESULT Print(`  
  
 `[in] DWORD grfFlags,`  
  
 `[in,out] DVTARGETDEVICE **pptd,`  
  
 `[in,out] PAGESET ** ppPageSet,`  
  
 `[in,out] STGMEDIUM **ppstgmOptions,`  
  
 `[in] IContinueCallback* pCallback,`  
  
 `[in] LONG nFirstPage,`  
  
 `[out] LONG *pcPagesPrinted,`  
  
 `[out] LONG *pnPageLast);`  
  
 `};`  
  
 Uso **IPrint::Print** de clientes e contêineres simplesmente instruir o documento para imprimir\-se uma vez que o documento é carregado, especificando sinalizadores de controle de impressão, o dispositivo de destino, as páginas para imprimir, e opções adicionais.  O cliente também pode controlar a continuação de impressão por meio da interface `IContinueCallback` \(consulte abaixo\).  
  
 Além disso, **IPrint::SetInitialPageNum** da suporte à capacidade de imprimir uma série de documentos como um numerando páginas direta, obviamente um benefício para contêineres ativas do documento gostaria da pasta do Office.  **IPrint::GetPageInfo** faz exibindo informações de paginação simples permitindo que o chamador recupera o número de página inicial passado anteriormente a **SetInitialPageNum** \(ou o número da página inicial padrão interna do documento\) e o número de páginas no documento.  
  
 Os objetos que oferecem suporte `IPrint` são marcados no Registro com a chave “imprimível” armazenada em CLSID do objeto:  
  
 HKEY\_CLASSES\_ROOT\\CLSID\\{...}\\Printable  
  
 `IPrint` geralmente é implementado no mesmo objeto que oferece suporte a `IPersistFile` ou `IPersistStorage`.  Os chamadores observe o recurso imprimir o estado persistente de uma determinada classe examinando no Registro para a chave “imprimível”.  Atualmente, “imprimível” indica suporte no mínimo `IPrint`; outras interfaces podem ser definidas no futuro que estariam disponíveis na `QueryInterface` onde **IPrint** representa apenas o nível base da suporte.  
  
 Durante um procedimento de cópia, talvez você queira que o cliente ou no contêiner que iniciou a impressão para controlar se a impressão deve continuar.  Por exemplo, o contêiner pode dar suporte a “um comando de PARAR CÓPIAS” que deve terminar o trabalho de cópia o mais rápido possível.  Para dar suporte a esse recurso, o cliente de um objeto imprimível pode implementar um objeto pequeno de coletor de notificação com a interface `IContinueCallback`:  
  
 `interface IContinueCallback : IUnknown`  
  
 `{`  
  
 `HRESULT FContinue(void);`  
  
 `HRESULT FContinuePrinting(`  
  
 `[in] LONG cPagesPrinted,`  
  
 `[in] LONG nCurrentPage,`  
  
 `[in] LPOLESTR pszPrintStatus);`  
  
 `};`  
  
 Esta interface é projetada para ser usável como uma função de retorno de chamada genérica de acompanhamento que usa o local para vários procedimentos de acompanhamento na API do Win32 \(como **AbortProc** para imprimir e **EnumMetafileProc** para a enumeração de metarquivo\).  Portanto esse design de interface é útil em uma ampla variedade de processos demorados.  
  
 No caso mais genéricas, a função de **IContinueCallback::FContinue** é chamada periodicamente por qualquer processo longo.  O objeto coletor retorna `S_OK` para continuar a operação, e **S\_FALSE** a interromper o mais rápido possível o procedimento.  
  
 **FContinue**, porém, não é usado no contexto de **IPrint::Print**; em vez disso, imprimindo usa **IContinueCallback::FContinuePrint**.  Qualquer objeto de impressão deve chamar periodicamente **FContinuePrinting** que transmite o número de páginas que têm impresso, o número da página que está sendo impressa, e uma cadeia de caracteres adicionais que descreve o status da cópia que o cliente pode optar por exibir o usuário \(como “página 5 de 19 "\).  
  
## Consulte também  
 [Contêineres de documento ativos](../mfc/active-document-containers.md)