---
title: "TN064: modelo Apartment Threading em controles ActiveX | Microsoft Docs"
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
  - "vc.controls.activex"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "threading de modelo de apartment"
  - "contêineres [C++], com multithread"
  - "contêiner multithread"
  - "Controles OLE, suporte a contêiner"
  - "TN064"
ms.assetid: b2ab4c88-6954-48e2-9a74-01d4a60df073
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN064: modelo Apartment Threading em controles ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Observe que essa técnica explica como habilitar a apartamento\- modelo de threading em um controle ActiveX.  Observe que a apartamento\- modelo de threading tem suporte apenas nas versões do Visual C\+\+ 4,2 ou posterior.  
  
## Que é Apartamento\- modelo de threading?  
 O modelo de STA. é uma abordagem suporte a objetos internos, como controles ActiveX, dentro de um contêiner de aplicativo multi\-threaded.  Embora o aplicativo pode ter vários threads, cada instância de um objeto inserido será atribuída a um STA. “,” que será executado em um thread.  Ou seja todas as chamadas em uma instância de um controle ocorrerão no mesmo thread.  
  
 No entanto, as instâncias diferentes do mesmo tipo de controle podem ser atribuídas a construção diferentes.  Assim, se várias instâncias de um controle compartilham os dados em comum \(por exemplo, dados estáticos ou globais\), o acesso aos dados compartilhados isso precisarão ser protegidos por um objeto de sincronização, como uma seção crítica.  
  
 Para obter detalhes completos no modelo de Threading Apartment, consulte [Processos e threads](http://msdn.microsoft.com/library/windows/desktop/ms684841)*na referência do programador OLE*.  
  
## Por que ofereça suporte à Apartamento\- modelo de threading?  
 Os controles que dão suporte à apartamento\- modelo de threading podem ser usados em aplicativos multi\-threaded de contêiner que também dão suporte ao modelo de. STA.  Se você não habilita a apartamento\- modelo de threading, você limitará o potencial definido contêineres em que o controle pode ser usado.  
  
 Habilitar a apartamento\- modelo de threading é fácil para a maioria dos controles, especialmente se tiverem nenhum quase dados compartilhados.  
  
## Proteção de dados compartilhados  
 Se o controle usa dados compartilhados, como uma variável de membro estático, acesso aos dados devem ser protegidos com uma seção crítica para impedir que mais de um thread modificar os dados ao mesmo tempo.  Para configurar essa finalidade de uma seção crítica, declare uma variável de membro estático da classe `CCriticalSection` na classe do controle.  Use as funções de membro de `Lock` e de **Desbloquear** deste objeto da seção crítica onde quer que o código acesse os dados compartilhados.  
  
 Considere, por exemplo, uma classe de controle que precisa manter uma cadeia de caracteres que é compartilhada por todas as instâncias.  Essa cadeia de caracteres pode ser mantida em uma variável de membro estático e ser protegida por uma seção crítica.  A declaração de classe do controle conteria o seguinte:  
  
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
  
 Acesso ao membro estático de `_strShared` pode ser protegido por seção crítica:  
  
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
  
## Registrando um controle Apartamento\-Modelo\-ciente  
 Os controles que dão suporte à apartamento\- modelo de threading devem indicar esse recurso no Registro, adicionando o valor chamado “ThreadingModel” com um valor de “STA.” na entrada do Registro de ID da classe com *a ID da classe*\\ chave de**InprocServer32** .  Para fazer essa chave a ser registrada automaticamente para o controle, o sinalizador de `afxRegApartmentThreading` no sexto parâmetro a `AfxOleRegisterControlClass`:  
  
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
        return AfxOleUnregisterClass(m_clsid, m_lpszProgID);  
}  
```  
  
 Se o projeto de controle foi gerado por ControlWizard na versão 4,1 do Visual C\+\+ ou posterior, esse sinalizador já estiver presente no seu código.  Nenhuma alteração será necessária para registrar o modelo de threading.  
  
 Se o projeto foi gerado por uma versão anterior de ControlWizard, seu código existente terá um valor booliano como o sexto parâmetro.  Se o parâmetro existente for TRUE, altere\-o para `afxRegInsertable | afxRegApartmentThreading`.  Se o parâmetro existente for FALSE, altere\-o para `afxRegApartmentThreading`.  
  
 Se o controle não segue as regras da apartamento\- modelo de threading, você não deve passar `afxRegApartmentThreading` nesse parâmetro.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)