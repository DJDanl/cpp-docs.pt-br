---
title: "As etapas em um aplicativo de cliente Gopher típico | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- WinInet classes [MFC], gopher
- Internet applications [MFC], gopher client applications
- Gopher client applications [MFC]
- Internet client applications [MFC], gopher table
ms.assetid: 3e4e1869-5da0-453d-8ba9-b648c894bb90
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5108e997336e53434ad33030c0e79be027aa4a98
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="steps-in-a-typical-gopher-client-application"></a>Etapas em um aplicativo cliente gopher típico
A tabela a seguir mostra as etapas que você pode executar em um aplicativo de cliente gopher típico.  
  
|Sua meta|Ações executadas|Efeitos|  
|---------------|----------------------|-------------|  
|Inicia uma sessão de gopher.|Criar um [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa WinInet e se conecta ao servidor.|  
|Conecte a um servidor gopher.|Use [CInternetSession::GetGopherConnection](../mfc/reference/cinternetsession-class.md#getgopherconnection).|Retorna um [CGopherConnection](../mfc/reference/cgopherconnection-class.md) objeto.|  
|Localize o primeiro recurso no gopher.|Use [CGopherFileFind::FindFile](../mfc/reference/cgopherfilefind-class.md#findfile).|Localiza o primeiro arquivo. Se nenhum arquivo for encontrado, retorna falso.|  
|Localize o recurso Avançar no gopher.|Use [CGopherFileFind::FindNextFile](../mfc/reference/cgopherfilefind-class.md#findnextfile).|Localiza o próximo arquivo. Se o arquivo não for encontrado, retorna falso.|  
|Abra o arquivo encontrado por **FindFile** ou `FindNextFile` para leitura.|Obter um localizador de gopher usando [CGopherFileFind::GetLocator](../mfc/reference/cgopherfilefind-class.md#getlocator). Use [CGopherConnection::OpenFile](../mfc/reference/cgopherconnection-class.md#openfile).|Abre o arquivo especificado pelo localizador. `OpenFile`Retorna um [CGopherFile](../mfc/reference/cgopherfile-class.md) objeto.|  
|Abra um arquivo usando um localizador de gopher que você fornecer.|Criar um localizador de gopher usando [CGopherConnection::CreateLocator](../mfc/reference/cgopherconnection-class.md#createlocator). Use [CGopherConnection::OpenFile](../mfc/reference/cgopherconnection-class.md#openfile).|Abre o arquivo especificado pelo localizador. `OpenFile`Retorna um [CGopherFile](../mfc/reference/cgopherfile-class.md) objeto.|  
|Ler o arquivo.|Use [CGopherFile](../mfc/reference/cgopherfile-class.md).|Lê o número especificado de bytes, usando um buffer que você fornecer.|  
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Trata todos os tipos de exceção de Internet comuns.|  
|Encerre a sessão de gopher.|Descarte o [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré-requisitos para Classes de cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
