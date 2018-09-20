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
ms.openlocfilehash: dd3dde01d87fccd1d19d947a1069fa92675e6053
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390336"
---
# <a name="steps-in-a-typical-internet-client-application"></a>Etapas em um aplicativo cliente da Internet típico

A tabela a seguir mostra as etapas que você pode executar em um aplicativo de cliente de Internet típico.

|Sua meta|Ações que você executar|Efeitos|
|---------------|----------------------|-------------|
|Iniciar uma sessão de Internet.|Criar uma [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Inicializa o WinInet e se conecta ao servidor.|
|Defina uma opção de consulta de Internet (tempo limite ou número de repetições, por exemplo).|Use [CInternetSession::SetOption](../mfc/reference/cinternetsession-class.md#setoption).|Retornará FALSE se a operação foi bem-sucedida.|
|Estabeleça uma função de retorno de chamada para monitorar o status da sessão.|Use [CInternetSession::EnableStatusCallback](../mfc/reference/cinternetsession-class.md#enablestatuscallback).|Estabelece um retorno de chamada para [CInternetSession::OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback). Substituir `OnStatusCallback` para criar sua própria rotina de retorno de chamada.|
|Se conecte a um servidor de Internet, o servidor da intranet ou o arquivo local.|Use [CInternetSession::OpenURL](../mfc/reference/cinternetsession-class.md#openurl).|Analisa o URL e abre uma conexão ao servidor especificado. Retorna um [CStdioFile](../mfc/reference/cstdiofile-class.md) (se você passar `OpenURL` um nome de arquivo local). Isso é o objeto por meio do qual você acessar os dados recuperados do servidor ou do arquivo.|
|Ler o arquivo.|Use [CInternetFile::Read](../mfc/reference/cinternetfile-class.md#read).|Lê o número especificado de bytes usando um buffer que você fornecer.|
|Trate exceções.|Use o [CInternetException](../mfc/reference/cinternetexception-class.md) classe.|Lida com todos os tipos de exceção comuns da Internet.|
|Encerre a sessão de Internet.|Descartar os [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto.|Limpa automaticamente identificadores de arquivos abertos e conexões.|

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Pré-requisitos para classes cliente da Internet](../mfc/prerequisites-for-internet-client-classes.md)<br/>
[Escrevendo um aplicativo cliente da Internet usando classes WinInet do MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)
