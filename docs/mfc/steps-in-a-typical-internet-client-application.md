---
title: As etapas em um aplicativo de cliente da Internet típico | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet client applications [MFC], general table
- WinInet classes [MFC], programming
- Internet applications [MFC], client applications
ms.assetid: 7aba135c-7c15-4e2f-8c34-bbaf792c89a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b1c7a7053b8378ea62dc0291dba1b79b794dd099
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381268"
---
# <a name="steps-in-a-typical-internet-client-application"></a>Etapas em um aplicativo cliente da Internet típico
A tabela a seguir mostra as etapas que você pode executar em um aplicativo típico do cliente da Internet.  
  
|Sua meta|Ações executadas|Efeitos|  
|---------------|----------------------|-------------|  
|Inicia uma sessão de Internet.|Criar um [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa WinInet e se conecta ao servidor.|  
|Defina uma opção de consulta da Internet (tempo limite ou o número de repetições, por exemplo).|Use [CInternetSession::SetOption](../mfc/reference/cinternetsession-class.md#setoption).|Retornará FALSE se a operação foi bem-sucedida.|  
|Estabelece uma função de retorno de chamada para monitorar o status da sessão.|Use [CInternetSession::EnableStatusCallback](../mfc/reference/cinternetsession-class.md#enablestatuscallback).|Estabelece um retorno de chamada para [CInternetSession::OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback). Substituir `OnStatusCallback` para criar sua própria rotina de retorno de chamada.|  
|Conecte-se a um servidor de Internet, o servidor da intranet ou o arquivo local.|Use [CInternetSession::OpenURL](../mfc/reference/cinternetsession-class.md#openurl).|Analisa a URL e abre uma conexão ao servidor especificado. Retorna um [CStdioFile](../mfc/reference/cstdiofile-class.md) (se você passar `OpenURL` um nome de arquivo local). Este é o objeto usado para acessar os dados recuperados do servidor ou do arquivo.|  
|Ler o arquivo.|Use [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read).|Lê o número especificado de bytes usando um buffer que você fornecer.|  
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Trata todos os tipos de exceção de Internet comuns.|  
|Encerre a sessão de Internet.|Descarte o [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré-requisitos para Classes de cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
