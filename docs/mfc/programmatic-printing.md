---
title: "Impressão programática | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- printing [MFC], active documents
- active documents [MFC], printing
- printing [MFC], programmatic
- IPrint interface
- printing [MFC]
ms.assetid: 3db0945b-5e13-4be4-86a0-6aecdae565bd
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 927a5d9b4bea41157c8cfac6f3dbfe42fc323bb2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="programmatic-printing"></a>Impressão programática
OLE fornecido os meios para identificar documentos persistentes (**GetClassFile**) e carregá-los em seu código associado (`CoCreateInstance`, **QueryInterface(IID_IPersistFile)**, **QueryInterface(IID_IPersistStorage)**, **IPersistFile:: Load**, e **IPersistStorage::Load**). Para aumentar ainda mais a impressão de documentos, contenção de documentos ativos (usando um projeto existente do OLE não acompanha originalmente OLE 2.0) apresenta uma interface de impressão padrão da base, `IPrint`, disponível por meio de qualquer objeto que pode carregar o estado persistente do tipo de documento. Cada modo de exibição de um documento ativo opcionalmente pode dar suporte a **IPrint** interface para fornecer esses recursos.  
  
 O `IPrint` interface é definida da seguinte maneira:  
  
```  
interface IPrint : IUnknown  
    {  
    HRESULT SetInitialPageNum([in] LONG nFirstPage);  
    HRESULT GetPageInfo(  
        [out] LONG *pnFirstPage,  
        [out] LONG *pcPages);  
    HRESULT Print(  
        [in] DWORD grfFlags,  
        [in,out] DVTARGETDEVICE **pptd,  
        [in,out] PAGESET ** ppPageSet,  
        [in,out] STGMEDIUM **ppstgmOptions,  
        [in] IContinueCallback* pCallback,  
        [in] LONG nFirstPage,  
        [out] LONG *pcPagesPrinted,  
        [out] LONG *pnPageLast);  
    };  
```  
  
 Os clientes e contêineres simplesmente usam **IPrint** para instruir o documento para imprimir em si, quando esse documento é carregado, especificando sinalizadores de controle de impressão, o dispositivo de destino, as páginas a serem impressas e opções adicionais. O cliente também pode controlar a continuação de impressão por meio da interface `IContinueCallback` (veja abaixo).  
  
 Além disso, **IPrint::SetInitialPageNum** oferece suporte à capacidade para imprimir uma série de documentos, como perfeitamente, obviamente uma numeração de páginas um benefício para contêineres de documento ativo como o Office Binder. **IPrint::GetPageInfo** torna exibindo informações de paginação simples, permitindo que o chamador recuperar a partir da página número anteriormente passado para **SetInitialPageNum** (ou padrão interna do documento número da página inicial) e o número de páginas do documento.  
  
 Objetos que dão suporte a `IPrint` são marcados no registro com a chave "Cálculo" armazenada em CLSID do objeto:  
  
 HKEY_CLASSES_ROOT\CLSID\\{...} \Printable  
  
 `IPrint`geralmente é implementado no mesmo objeto que oferece suporte a `IPersistFile` ou `IPersistStorage`. Os chamadores Observe a capacidade do estado persistente de uma classe de impressão programaticamente através do registro para a chave "Cálculo". No momento, "Impressão" indica suporte para pelo menos `IPrint`; outras interfaces podem ser definidos no futuro que estaria disponível por meio de `QueryInterface` onde **IPrint** simplesmente representa o nível de base de suporte.  
  
 Durante um procedimento de impressão, talvez você queira o cliente ou o contêiner que iniciou a impressão para controlar se a impressão deve continuar. Por exemplo, o contêiner pode oferecer suporte a um comando "Parar Print" que deve encerrar o trabalho de impressão assim que possível. Para dar suporte a esse recurso, o cliente de um objeto pode implementar um objeto de coletor de notificação pequeno com a interface `IContinueCallback`:  
  
```  
interface IContinueCallback : IUnknown  
    {  
    HRESULT FContinue(void);  
    HRESULT FContinuePrinting(  
        [in] LONG cPagesPrinted,  
        [in] LONG nCurrentPage,  
        [in] LPOLESTR pszPrintStatus);  
    };  
```  
  
 Essa interface é projetada para ser útil como uma função de retorno de chamada de continuação genérico que assume o lugar de vários procedimentos de continuação na API do Win32 (como o **AbortProc** para impressão e o  **EnumMetafileProc** para enumeração de metarquivo). Portanto, esse design de interface é útil em uma ampla variedade de processos demorados.  
  
 Nos casos mais genéricos, o **IContinueCallback::FContinue** função é chamada periodicamente por qualquer processo demorado. Retorna o objeto coletor `S_OK` para continuar a operação e **S_FALSE** para interromper o procedimento assim que possível.  
  
 **FContinue**, no entanto, não é usado no contexto de **IPrint**; em vez disso, imprimindo usa **IContinueCallback::FContinuePrint**. Qualquer objeto de impressão deve chamar periodicamente **FContinuePrinting** passando o número de páginas que tenha sido impressão, o número da página seja impresso e uma cadeia de caracteres adicional que descreve o status de impressão que o cliente pode Escolha esta opção para exibir para o usuário (como "página 5 de 19").  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de documento ativos](../mfc/active-document-containers.md)

