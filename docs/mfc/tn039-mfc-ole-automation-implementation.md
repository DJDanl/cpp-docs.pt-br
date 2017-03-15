---
title: "TN039: implementa&#231;&#227;o de automa&#231;&#227;o MFC/OLE | Microsoft Docs"
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
  - "vc.mfc.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Automação, pontos de entrada da interface COM MFC"
  - "Interface IDispatch"
  - "MFC, Suporte COM"
  - "MFC, OLE DB e"
  - "TN039"
ms.assetid: 765fa3e9-dd54-4f08-9ad2-26e0546ff8b6
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN039: implementa&#231;&#227;o de automa&#231;&#227;o MFC/OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
## Visão geral da interface IDispatch OLE  
 A interface de `IDispatch` é um conjunto de mídias por que os aplicativos expõe métodos e propriedades de forma que outros aplicativos como o Visual Basic, ou outros idiomas, podem utilizar os recursos de aplicativo.  A parte mais importante desta interface é a função de **IDispatch::Invoke** .  O usa “distribuição” MFC mapeiam para implementar **IDispatch::Invoke**.  O mapa de expedição fornece informações sobre a implementação de MFC no layout ou “” na forma do `CCmdTarget`\- classes derivadas, de modo que pode manipular diretamente as propriedades do objeto, ou chama funções de membro dentro de seu objeto para atender solicitações de **IDispatch::Invoke** .  
  
 Em geral, ClassWizard e o MFC cooperam para ocultar a maioria dos detalhes de automação OLE do programador de aplicativo.  O programador concentra\-se na funcionalidade real para expor no aplicativo e não se precisa se preocupar sobre o indicação subjacente.  
  
 Há casos, porém, onde é necessário entender o que o MFC está fazendo os bastidores.  Essa observação tratará como a estrutura atribui **DISPID**s às funções de membro e propriedades.  O conhecimento dos usos MFC do algoritmo para atribuir **DISPID**s é necessária apenas quando você precisa saber os IDs, como quando você cria uma biblioteca de “tipo” para os objetos do seu aplicativo.  
  
## Atribuição de DISPID MFC  
 Embora o usuário final de automação \(um usuário do Visual Basic, por exemplo\), veja os nomes reais das propriedades e dos métodos habilitados automação em seu código \(como obj.ShowWindow\), a implementação de **IDispatch::Invoke** não receberá os nomes reais.  Por motivo da otimização, recebe **DISPID**, que é uma “cookie” mágica de 32 bits que descreve o método ou da propriedade que devem ser acessados.  Esses valores de **DISPID** são retornados da implementação de `IDispatch` com outro método, **IDispatch::GetIDsOfNames**chamado.  Um aplicativo cliente de automação `GetIDsOfNames` chama uma vez para cada membro ou a propriedade que pretende acessar, e os armazena em cachê para chamadas posteriores para **IDispatch::Invoke**.  Dessa forma, a pesquisa cara de cadeia de caracteres é feita somente uma vez por uso de objeto, em vez de uma vez pela chamada de **IDispatch::Invoke** .  
  
 O MFC determina **DISPID**s para cada método e a propriedade com base em duas coisas:  
  
-   A distância da parte superior da distribuição \(1 relativo\)  
  
-   A distância do mapa de expedição da maioria de classe derivada \(0\) parentes  
  
 **DISPID** é dividido em duas partes.  **LOWORD** de **DISPID** contém o primeiro componente, a distância da parte superior da remessa.  **HIWORD** contém a distância da maioria da classe derivada.  Por exemplo:  
  
```  
class CDispPoint : public CCmdTarget  
{  
public:  
    short m_x, m_y;  
    ...  
    DECLARE_DISPATCH_MAP()  
    ...  
};  
  
class CDisp3DPoint : public CDispPoint  
{  
public:  
    short m_z;  
    ...  
    DECLARE_DISPATCH_MAP()  
    ...  
};  
  
BEGIN_DISPATCH_MAP(CDispPoint, CCmdTarget)  
    DISP_PROPERTY(CDispPoint, "x", m_x, VT_I2)  
    DISP_PROPERTY(CDispPoint, "y", m_y, VT_I2)  
END_DISPATCH_MAP()  
  
BEGIN_DISPATCH_MAP(CDisp3DPoint, CDispPoint)  
    DISP_PROPERTY(CDisp3DPoint, "z", m_z, VT_I2)  
END_DISPATCH_MAP()  
```  
  
 Como você pode ver, há duas classes, que expõe interfaces DE automação OLE.  Uma dessas classes é derivado de outro e aproveita assim a funcionalidade da classe base, incluindo a parte de automação OLE \(propriedades de “x” e “y” nesse caso\).  
  
 O **DISPID**MFC gerará o para a classe CDispPoint como segue:  
  
```  
property X    (DISPID)0x00000001  
property Y    (DISPID)0x00000002  
```  
  
 Como as propriedades não estão em uma classe base, **HIWORD** de **DISPID** sempre será zero \(a distância da maioria de classe derivada para CDispPoint é zero\).  
  
 O **DISPID**MFC gerará o para a classe CDisp3DPoint como segue:  
  
```  
property Z    (DISPID)0x00000001  
property X    (DISPID)0x00010001  
property Y    (DISPID)0x00010002  
```  
  
 A propriedade de Z é determinada **DISPID** com **HIWORD** zero desde que é definida na classe que é exposta as propriedades, CDisp3DPoint.  Como as propriedades X e Y são em uma classe base, **HIWORD** de **DISPID** sido 1, pois a classe na qual essas propriedades são definidas estão em uma distância de uma derivação da maioria da classe derivada.  
  
> [!NOTE]
>  **LOWORD** sempre é determinado pela posição no mapa, mesmo se houver entradas no mapa com **DISPID** explícito \(consulte a próxima seção para obter informações sobre as versões de **\_ID** de macros de `DISP_PROPERTY` e de `DISP_FUNCTION` \).  
  
## Recursos avançados do mapa de expedição MFC  
 Há vários recursos adicionais que ClassWizard não da suporte a esta versão do Visual C\+\+.  ClassWizard oferece suporte a `DISP_FUNCTION`, `DISP_PROPERTY`, e `DISP_PROPERTY_EX` que definem um método, uma propriedade variável de membro, e a obtenção\/definem a propriedade da função de membro, respectivamente.  Esses recursos são geralmente tudo o que é necessário para criar a maioria dos servidores de automação.  
  
 Os seguintes macros adicionais podem ser usados quando as macros suporte ClassWizard não são suficientes: `DISP_PROPERTY_NOTIFY`, e `DISP_PROPERTY_PARAM`.  
  
## DISP PROPERTY NOTIFY \- descrição macro  
  
```  
  
        DISP_PROPERTY_NOTIFY(   
   theClass,   
   pszName,   
   memberName,   
   pfnAfterSet,   
   vtPropType   
)  
```  
  
## Comentários  
  
### Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da propriedade.  
  
 `memberName`  
 Nome da variável de membro em que a propriedade é armazenada.  
  
 `pfnAfterSet`  
 Nome da função de membro para chamar quando a propriedade é alterada.  
  
 `vtPropType`  
 Um valor que especifica o tipo de propriedade.  
  
## Comentários  
 Esta macro é bem como `DISP_PROPERTY`, exceto que aceita um argumento adicional.  O argumento adicional, *pfnAfterSet,* deve ser uma função de membro que não retorna nada e não usa nenhum parâmetro, “OnPropertyNotify nulo \(\)”.  Será chamado **depois que** a variável de membro foi alterado.  
  
## DISP PROPERTY PARAM \- descrição macro  
  
```  
  
        DISP_PROPERTY_PARAM(   
   theClass,  
   pszName,  
   pfnGet,  
   pfnSet,  
   vtPropType,  
   vtsParams   
)  
```  
  
## Comentários  
  
### Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da propriedade.  
  
 `memberGet`  
 Nome da função de membro usada para obter a propriedade.  
  
 `memberSet`  
 O nome da função de membro usado para definir a propriedade.  
  
 `vtPropType`  
 Um valor que especifica o tipo de propriedade.  
  
 `vtsParams`  
 Uma cadeia de caracteres de espaço VTS\_ separados para cada parâmetro.  
  
## Comentários  
 Bem como a macro de `DISP_PROPERTY_EX` , esta macro define uma propriedade acessada com separado obtém e define as funções de membro.  Esta macro, porém, permite que você especifica uma lista de parâmetros para a propriedade.  Isso é útil para implementar as propriedades que são indexadas ou com parâmetros em alguma outra forma.  Os parâmetros serão colocados sempre primeiro, seguido pelo novo valor da propriedade.  Por exemplo:  
  
```  
DISP_PROPERTY_PARAM(CMyObject, "item", GetItem, SetItem, VT_DISPATCH,    VTS_I2 VTS_I2)  
```  
  
 corresponderia para obter e definir as funções de membro:  
  
```  
LPDISPATCH CMyObject::GetItem(short row, short col)  
void CMyObject::SetItem(short row, short col, LPDISPATCH newValue)  
```  
  
## DISP\_XXXX\_ID — descrições macro  
  
```  
  
        DISP_FUNCTION_ID(   
   theClass,  
   pszName,  
   dispid,  
   pfnMember,  
   vtRetVal,  
   vtsParams   
) DISP_PROPERTY_ID(   
   theClass,  
   pszName,  
   dispid,  
   memberName,  
   vtPropType   
) DISP_PROPERTY_NOTIFY_ID(   
   theClass,  
   pszName,  
   dispid,  
   memberName,  
   pfnAfterSet,  
   vtPropType   
) DISP_PROPERTY_EX_ID(   
   theClass,  
   pszName,  
   dispid,  
   pfnGet,  
   pfnSet,  
   vtPropType   
) DISP_PROPERTY_PARAM_ID(   
   theClass,  
   pszName,  
   dispid,  
   pfnGet,  
   pfnSet,  
   vtPropType,  
   vtsParams   
)  
```  
  
## Comentários  
  
### Parâmetros  
 `theClass`  
 Nome da classe.  
  
 `pszName`  
 Nome externo da propriedade.  
  
 `dispid`  
 O DISPID fixo para a propriedade ou o método.  
  
 `pfnGet`  
 Nome da função de membro usada para obter a propriedade.  
  
 `pfnSet`  
 O nome da função de membro usado para definir a propriedade.  
  
 `memberName`  
 O nome da variável de membro ao mapear para a propriedade  
  
 `vtPropType`  
 Um valor que especifica o tipo de propriedade.  
  
 `vtsParams`  
 Uma cadeia de caracteres de espaço VTS\_ separados para cada parâmetro.  
  
## Comentários  
 Esses macros permitem que você especifique **DISPID** em vez de deixar o MFC o atribuirá automaticamente um.  Esses macros avançados têm os mesmos nomes exceto se a ID é anexado ao nome da macro \(por exemplo.  **DISP\_PROPERTY\_ID**\) e o ID são determinados pelo parâmetro especificado imediatamente depois do parâmetro de `pszName` .  Consulte AFXDISP.H para obter mais informações sobre esses macros.  As entradas de **\_ID** devem ser colocadas no final da remessa.  Afetará a geração automática de **DISPID** da mesma maneira que uma versão não de**\_ID** de macro \( **DISPID**s é determinado pela posição\).  Por exemplo:  
  
```  
BEGIN_DISPATCH_MAP(CDisp3DPoint, CCmdTarget)  
    DISP_PROPERTY(CDisp3DPoint, "y", m_y, VT_I2)  
    DISP_PROPERTY(CDisp3DPoint, "z", m_z, VT_I2)  
    DISP_PROPERTY_ID(CDisp3DPoint, "x", 0x00020003, m_x, VT_I2)  
END_DISPATCH_MAP()  
```  
  
 MFC O gerará DISPIDs da classe CDisp3DPoint como segue:  
  
```  
property X    (DISPID)0x00020003  
property Y    (DISPID)0x00000002  
property Z     (DISPID)0x00000001  
```  
  
 Especifique **DISPID** fixo é útil manter a compatibilidade com versões anteriores para uma interface anteriormente existente de distribuição, ou para implementar determinado sistema definiu os métodos ou propriedades \(indicados com frequência por **DISPID**negativo, como a coleção de **DISPID\_NEWENUM** \).  
  
#### Recuperando a interface IDispatch para um COleClientItem  
 Muitos servidores oferecerão suporte à automação dentro de seus objetos do documento, junto com a funcionalidade OLE do servidor.  Para obter acesso a essa interface de automação, é necessário acessar diretamente a variável de membro de **COleClientItem::m\_lpObject** .  O código a seguir recupera a interface de `IDispatch` para um objeto derivado de `COleClientItem`.  Você pode incluir código a seguir em seu aplicativo se você encontrar essa funcionalidade necessária:  
  
```  
LPDISPATCH CMyClientItem::GetIDispatch()  
{  
    ASSERT_VALID(this);  
    ASSERT(m_lpObject != NULL);  
  
    LPUNKNOWN lpUnk = m_lpObject;  
  
    Run();    // must be running  
  
    LPOLELINK lpOleLink = NULL;  
    if (m_lpObject->QueryInterface(IID_IOleLink,   
        (LPVOID FAR*)&lpOleLink) == NOERROR)  
    {  
        ASSERT(lpOleLink != NULL);  
        lpUnk = NULL;  
        if (lpOleLink->GetBoundSource(&lpUnk) != NOERROR)  
        {  
            TRACE0("Warning: Link is not connected!\n");  
            lpOleLink->Release();  
            return NULL;  
        }  
        ASSERT(lpUnk != NULL);  
    }  
  
    LPDISPATCH lpDispatch = NULL;  
    if (lpUnk->QueryInterface(IID_IDispatch, &lpDispatch)   
        != NOERROR)  
    {  
        TRACE0("Warning: does not support IDispatch!\n");  
        return NULL;  
    }  
  
    ASSERT(lpDispatch != NULL);  
    return lpDispatch;  
}  
```  
  
 A interface de expedição retornada dessa função pode ser usada diretamente ou anexado a `COleDispatchDriver` para acesso do tipo seguro.  Se você usá\-la diretamente, certifique\-se de que você chama seu membro de **Versão** quando através do ponteiro \(com o destruidor de `COleDispatchDriver` faz isso por padrão\).  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)