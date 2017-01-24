---
title: "Controles MFC ActiveX: localizando um controle ActiveX | Microsoft Docs"
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
  - "LocaleID"
  - "AfxOleRegisterTypeLib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Propriedades de ambiente LocaleID"
  - "localização, Controles ActiveX"
  - "Exemplo de LOCALIZE [MFC]"
  - "Controles ActiveX MFC, localizando"
ms.assetid: a44b839a-c652-4ec5-b824-04392708a5f9
caps.latest.revision: 12
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles MFC ActiveX: localizando um controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve os procedimentos para localizar interfaces de controle ActiveX.  
  
 Se você quiser adaptar um controle ActiveX a um mercado internacional, talvez você queira localizar o controle.  As janelas oferecem suporte a vários idiomas além do inglês padrão, incluindo o alemão, francês, e o sueco.  Isso pode experimentar problemas para o controle se sua interface estará em inglês\).  
  
 Em geral, os controles ActiveX devem sempre basear a localidade na propriedade de ambiente de LocaleID.  Há três modos de fazer isso:  
  
-   Carregar os recursos, sempre sob demanda, com base no valor atual da propriedade de ambiente de LocaleID.  O exemplo de [LOCALIZE](../top/visual-cpp-samples.md) MFC controles ActiveX usa essa estratégia.  
  
-   Carregar recursos quando o primeiro controle é colocado entre aspas como exemplo, com base na propriedade de ambiente de LocaleID, e usa esses recursos para todas as outras instâncias.  Este artigo demonstra essa estratégia.  
  
    > [!NOTE]
    >  Isso não funcionará corretamente em alguns casos, se as instâncias futuras têm localidades diferentes.  
  
-   Use a função da notificação de **OnAmbientChanged** para carregar dinamicamente os recursos adequados para a localidade do contêiner.  
  
    > [!NOTE]
    >  Isso funcionará para o controle, mas a DLL de tempo de execução não atualizará dinamicamente seus próprios recursos quando a propriedade de ambiente de LocaleID é alterado.  Além disso, as dlls de tempo de execução para controles ActiveX usam a localidade do thread para determinar a localidade para seus recursos.  
  
 O restante deste artigo descreve duas estratégias de localização.  A primeira estratégia [localiza a interface de programação de controle](#_core_localizing_your_control.92.s_programmability_interface) \(nomes das propriedades, os métodos, e os eventos\).  A segunda estratégia [localiza a interface de usuário de controle](#_core_localizing_the_control.92.s_user_interface), usando a propriedade de ambiente do LocaleID do contêiner.  Para ver uma demonstração de localização de controle, consulte o exemplo de [LOCALIZE](../top/visual-cpp-samples.md)MFC controles ActiveX.  
  
##  <a name="_core_localizing_your_control.92.s_programmability_interface"></a> Localizando a interface de programação de controle  
 Ao localizar a interface de programação de controle \(a interface usada por programadores que gravam os aplicativos que usam o controle\), você deverá criar uma versão modificada do arquivo de controle .IDL \(um script para criar a biblioteca de tipos do controle\) para cada idioma você pretende dar suporte.  Esse é o único local que você precisa localizar os nomes de propriedade do controle.  
  
 Quando você desenvolve um controle localizado, inclua a ID de localidade como um atributo no nível da biblioteca de tipos.  Por exemplo, se você desejar fornecer uma biblioteca de tipos com nomes de propriedade localizada francês, faça uma cópia do SAMPLE.IDL arquivamento, e denomine\-a SAMPLEFR.IDL.  Adicionar um atributo de identificação de localidade do arquivo de backup \(a identificação de localidade do francês é 0x040c\), semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFC_AxLoc#1](../mfc/codesnippet/CPP/mfc-activex-controls-localizing-an-activex-control_1.idl)]  
  
 Alterar os nomes das propriedades em SAMPLEFR.IDL aos seus equivalentes em francês, e então use MKTYPLIB.EXE para gerar a biblioteca francesa do tipo, SAMPLEFR.TLB.  
  
 Para criar várias bibliotecas localizadas do tipo você pode adicionar todos os arquivos encontrados de .IDL ao projeto e serão criados automaticamente.  
  
#### Para adicionar um arquivo de .IDL ao controle ActiveX projeto  
  
1.  Com o projeto de controle aberto, no menu de **Projeto** , clique **Adicionar Item Existente**.  
  
     A caixa de diálogo de **Adicionar Item Existente** é exibida.  
  
2.  Se necessário, selecione a unidade e diretório para exibir.  
  
3.  Na caixa de **Arquivos do tipo** , **Todos os arquivos \(\*.\*\)**selecione.  
  
4.  Na caixa de listagem de arquivo, clique duas vezes no arquivo de .IDL você deseja inserir no projeto.  
  
5.  Clique **Abrir** quando você adicionou todos os arquivos necessários de .IDL.  
  
 Como os arquivos foram adicionados ao projeto, serão criados enquanto o resto do projeto é compilado.  As bibliotecas localizadas do tipo estão localizadas no diretório atual do projeto do controle ActiveX.  
  
 Em seu código, os nomes de propriedade interna \(normalmente em inglês\) são usados sempre e nunca encontrados.  Isso inclui o mapa de expedição de controle, a propriedade troca de funções, e seu código de troca de dados da página de propriedades.  
  
 Apenas um arquivo de biblioteca de tipos .TLB \(\) pode ser associado nos recursos do arquivo de implementação de controle \(.OCX\).  Essa é geralmente a versão com \(normalmente, os nomes padronizados inglês\).  Para enviar uma versão localizada do controle que você precisa enviar o .OCX \(que já tiver sido associado à versão da opção .TLB\) e o .TLB para a localidade apropriado.  Isso significa que somente o .OCX é necessário para versões inglês, desde que o .TLB correto já tiver sido associado.  Para outras localidades, a biblioteca de tipo localizado também deve ser enviada com o .OCX.  
  
 Para garantir que os clientes do controle pode encontrar a biblioteca de tipo localizado, registre seus arquivos específicos de localidade de .TLB na seção de TypeLib do Registro do sistema do windows.  O terceiro parâmetro \(normalmente opcional\) da função de [AfxOleRegisterTypeLib](../Topic/AfxOleRegisterTypeLib.md) é fornecido para essa finalidade.  O exemplo a seguir registra uma biblioteca francesa de tipo para um controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxLoc#2](../mfc/codesnippet/CPP/mfc-activex-controls-localizing-an-activex-control_2.cpp)]  
  
 Quando o controle é registrado, a função de `AfxOleRegisterTypeLib` automaticamente o procurará o arquivo especificado de .TLB no mesmo diretório que o controle e registrá\-lo na base de dados do registro do windows.  Se o arquivo de .TLB não for localizado, a função não tem nenhum efeito.  
  
##  <a name="_core_localizing_the_control.92.s_user_interface"></a> Localizando a interface de usuário de controle  
 Para localizar a interface do usuário de um controle, coloque os recursos usuário visíveis de qualquer controle \(como páginas de propriedades e mensagens de erro\) na DLL de recursos específicos do idioma.  Depois você pode usar a propriedade de ambiente do LocaleID do contêiner para selecionar o DLL apropriado para a localidade do usuário.  
  
 O exemplo de código a seguir demonstra uma abordagem para localizar e carregar a DLL de recurso para uma localidade específica.  Essa função de membro, `GetLocalizedResourceHandle` chamado para este exemplo, pode ser uma função de membro da classe do controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxLoc#3](../mfc/codesnippet/CPP/mfc-activex-controls-localizing-an-activex-control_3.cpp)]  
  
 Observe que a ID de subidioma pode ser feito check\-in cada caso da instrução switch, para fornecer o local mais especializada.  Para ver uma demonstração dessa função, consulte a função de `GetResourceHandle` no exemplo de [LOCALIZE](../top/visual-cpp-samples.md)MFC controles ActiveX.  
  
 Quando o controle é carrega primeiro em um contêiner, [COleControl::AmbientLocaleID](../Topic/COleControl::AmbientLocaleID.md) pode chamar para recuperar a ID de localidade  O controle pode passar o valor retornado da identificação de localidade à função de `GetLocalizedResourceHandle` , que carrega a biblioteca adequada de recursos.  O controle deve passar o identificador resultante, se houver, a [AfxSetResourceHandle](../Topic/AfxSetResourceHandle.md):  
  
 [!code-cpp[NVC_MFC_AxLoc#4](../mfc/codesnippet/CPP/mfc-activex-controls-localizing-an-activex-control_4.cpp)]  
  
 Coloque o exemplo de código anterior em uma função de membro de controle, como uma substituição de [COleControl::OnSetClientSite](../Topic/COleControl::OnSetClientSite.md).  Além disso, `m_hResDLL` deve ser uma variável de membro da classe do controle.  
  
 Você pode usar lógica semelhante para localizar a página de propriedades de um controle.  Para localizar a página de propriedades, adicione o código semelhante ao exemplo no arquivo de implementação da página de propriedades \(em uma substituição de [COlePropertyPage::OnSetPageSite](../Topic/COlePropertyPage::OnSetPageSite.md)\):  
  
 [!code-cpp[NVC_MFC_AxLoc#5](../mfc/codesnippet/CPP/mfc-activex-controls-localizing-an-activex-control_5.cpp)]  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)