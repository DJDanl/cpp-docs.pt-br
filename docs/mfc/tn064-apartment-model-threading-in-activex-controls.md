---
title: 'TN064: Modelo Apartment Threading em controles ActiveX | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.controls.activex
dev_langs:
- C++
helpviewer_keywords:
- OLE controls [MFC], container support
- containers [MFC], multithreaded
- TN064 [MFC]
- multithread container [MFC]
- apartment model threading [MFC]
ms.assetid: b2ab4c88-6954-48e2-9a74-01d4a60df073
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 07730d6c078dcc8fcd7ea1406f8cff6f665c9919
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn064-apartment-model-threading-in-activex-controls"></a>TN064: modelo Apartment Threading em controles ActiveX
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta nota técnica explica como habilitar o modelo apartment threading em um controle ActiveX. Observe que modelo apartment threading só tem suporte em versões do Visual C++ 4.2 ou posteriores.  
  
## <a name="what-is-apartment-model-threading"></a>O que é o modelo Apartment Threading  
 O modelo de apartment é uma abordagem para oferecer suporte a objetos inseridos, como controles ActiveX, dentro de um aplicativo de contêiner multithread. Embora o aplicativo pode ter vários threads, cada instância de um objeto incorporado será atribuída a um "STA," que será executado em apenas um thread. Em outras palavras, todas as chamadas para uma instância de um controle ocorrerá no mesmo thread.  
  
 No entanto, diferentes instâncias do mesmo tipo de controle podem ser atribuídas a apartments diferentes. Portanto, se várias instâncias de um controle de compartilharem os dados em comum (por exemplo, dados estáticos ou global), acesso aos dados compartilhados precisará ser protegido por um objeto de sincronização, como uma seção crítica.  
  
 Para obter detalhes completos sobre o modelo apartment threading, consulte [processos e Threads](http://msdn.microsoft.com/library/windows/desktop/ms684841) no *referência do programador de OLE*.  
  
## <a name="why-support-apartment-model-threading"></a>Por que suporta o modelo Apartment Threading  
 Controles que oferecem suporte a modelo apartment threading podem ser usados em aplicativos multithread de contêiner que também dar suporte ao modelo de apartment. Se você não habilitar o modelo apartment threading, você limitará o conjunto potencial de contêineres no qual o controle pode ser usado.  
  
 Habilitar o modelo apartment threading é fácil para a maioria dos controles, especialmente se eles têm pouco ou nenhum dados compartilhados.  
  
## <a name="protecting-shared-data"></a>Protegendo dados compartilhados  
 Se o controle usa dados compartilhados, como uma variável de membro estático, o acesso ao que os dados devem ser protegidos com uma seção crítica para impedir que mais de um thread de modificação de dados ao mesmo tempo. Para configurar uma seção crítica para essa finalidade, declarar uma variável de membro estático da classe `CCriticalSection` na classe do controle. Use o `Lock` e **Unlock** funções de membro desta seção crítica do objeto sempre que seu código acessa os dados compartilhados.  
  
 Considere, por exemplo, uma classe de controle que precisa para manter uma cadeia de caracteres que é compartilhada por todas as instâncias. Essa cadeia de caracteres pode ser mantida em uma variável de membro estático e protegida por uma seção crítica. Declaração de classe do controle deve conter o seguinte:  
  
```  
class CSampleCtrl : public COleControl  
{  
 ...  
    static CString _strShared;  
    static CCriticalSection _critSect;  
};  
```  
  
 A implementação da classe inclui definições para essas variáveis:  
  
```  
int CString CSampleCtrl::_strShared;  
CCriticalSection CSampleCtrl::_critSect;  
```  
  
 Acesse o `_strShared` membro estático, em seguida, pode ser protegido por seção crítica:  
  
```  
void CSampleCtrl::SomeMethod()  
{  
    _critSect.Lock();
if (_strShared.Empty())  
    _strShared = "<text>";  
    _critSect.Unlock();

 ...  
}  
```  
  
## <a name="registering-an-apartment-model-aware-control"></a>Registrar um controle de reconhecimento de modelo de Apartment  
 Controles que oferecem suporte a modelo apartment threading devem indicar esse recurso no registro, adicionando o valor nomeado "ThreadingModel" com um valor de "Apartment" na sua entrada de registro de ID de classe no *id da classe* \\ **InprocServer32** chave. Para fazer com que essa chave a ser registrado automaticamente para o seu controle, passar o `afxRegApartmentThreading` sinalizador no sexto parâmetro para `AfxOleRegisterControlClass`:  
  
```  
BOOL CSampleCtrl::CSampleCtrlFactory::UpdateRegistry(BOOL bRegister)  
{  
    if (bRegister)  
    return AfxOleRegisterControlClass(
    AfxGetInstanceHandle(), 
    m_clsid, 
    m_lpszProgID, 
    IDS_SAMPLE, 
    IDB_SAMPLE, 
    afxRegApartmentThreading, 
    _dwSampleOleMisc, 
    _tlid, 
    _wVerMajor, 
    _wVerMinor);

 else  
    return AfxOleUnregisterClass(m_clsid,
    m_lpszProgID);

}  
```  
  
 Se seu projeto de controle foi gerado pelo ControlWizard no Visual C++ versão 4.1 ou posterior, esse sinalizador já estará presente no seu código. Nenhuma alteração é necessária registrar o modelo de threading.  
  
 Se seu projeto foi gerado por uma versão anterior do ControlWizard, seu código existente terá um valor booliano como o sexto parâmetro. Se o parâmetro existente for TRUE, altere-o para `afxRegInsertable | afxRegApartmentThreading`. Se o parâmetro existente for FALSE, altere-o para `afxRegApartmentThreading`.  
  
 Se o controle não segue as regras de modelo apartment threading, você não deve passar `afxRegApartmentThreading` nesse parâmetro.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

