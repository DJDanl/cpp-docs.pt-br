---
title: "TN002: formato de dados do objeto persistente | Microsoft Docs"
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
  - "vc.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CArchive, suporte para dados persistentes"
  - "objetos C++ persistentes"
  - "dados de objetos persistentes"
  - "TN002"
  - "Macro VERSIONABLE_SCHEMA"
ms.assetid: 553fe01d-c587-4c8d-a181-3244a15c2be9
caps.latest.revision: 22
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN002: formato de dados do objeto persistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve as rotinas de MFC que dão suporte a objetos persistentes C\+\+ e o formato dos dados do objeto quando for armazenado em um arquivo.  Isso se aplica apenas às classes com macros de [DECLARE\_SERIAL](../Topic/DECLARE_SERIAL.md) e de [IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md) .  
  
## O problema  
 A implementação de MFC para dados persistentes os repositórios de dados para muitos objetos em uma única parte contíguo de um arquivo.  O método de `Serialize` do objeto converte os dados do objeto em um formato binário do compact.  
  
 A implementação garante que todos os dados serão salvos no mesmo formato usando [Classe de CArchive](../mfc/reference/carchive-class.md).  Usa um objeto de `CArchive` como um tradutor.  Esse objeto persistir de tempo em que é criado até que você chame [CArchive::Close](../Topic/CArchive::Close.md).  Esse método pode ser chamado explicitamente pelo programador ou implicitamente por destruidor quando o programa o escopo que contém `CArchive`.  
  
 Essa observação descreve a implementação dos membros [CArchive::ReadObject](../Topic/CArchive::ReadObject.md) e [CArchive::WriteObject](../Topic/CArchive::WriteObject.md)de `CArchive` .  Você encontrará o código para essas funções em Arcobj.cpp, e a implementação principal para `CArchive` em Arccore.cpp.  O código de usuário não chama `ReadObject` e `WriteObject` diretamente.  Em vez disso, esses objetos são usados pelos operadores classe tipo seguro específicos de inserção e de extração que são gerados automaticamente por macros de `DECLARE_SERIAL` e de `IMPLEMENT_SERIAL` .  O código a seguir mostra como `WriteObject` e `ReadObject` é chamado implicitamente:  
  
```  
class CMyObject : public CObject  
{  
    DECLARE_SERIAL(CMyObject)  
};  
  
IMPLEMENT_SERIAL(CMyObj, CObject, 1)  
  
// example usage (ar is a CArchive&)  
CMyObject* pObj;  
CArchive& ar;  
ar << pObj;        // calls ar.WriteObject(pObj)  
ar >> pObj;        // calls ar.ReadObject(RUNTIME_CLASS(CObj))  
```  
  
## Objetos de salvar a CArchive::WriteObject \(Store\)  
 Os dados do cabeçalho de gravações de `CArchive::WriteObject` do método que são usados para recriar o objeto.  Esses dados consiste em duas partes: o tipo de objeto e o estado do objeto.  Esse método também é responsável por manter a identidade do objeto que está sendo gravado, de modo que somente uma única cópia foi salva, independentemente do número de ponteiros ao objeto \(inclusive ponteiros circulares\).  
  
 Salvar \(inserir\) e restaurar objetos \(extrair\) dependem de várias “constantes manifestas”. Estes são valores que são armazenados em binário e fornecem informações importantes ao arquivo morto \(observe o prefixo “w” indica quantidades de 16 bits\):  
  
|Marca|Descrição|  
|-----------|---------------|  
|wNullTag|Usado para os ponteiros NULL do objeto \(0\).|  
|wNewClassTag|Indica que descrição da classe que segue é nova neste contexto de arquivo morto \(\- 1\).|  
|wOldClassTag|Indica que a classe do objeto que está sendo lido esteve considerada nesse contexto \(0x8000\).|  
  
 Ao armazenar objetos, o arquivo morto mantém [CMapPtrToPtr](../mfc/reference/cmapptrtoptr-class.md) \( `m_pStoreMap`\) que é um mapeamento de um objeto armazenado em um identificador persistente de 32 bits \(PID\).  Um PID é atribuído a cada objeto exclusivo e a cada nome exclusivo da classe que é salvo no contexto de arquivo morto.  Esses são PIDs em sequência iniciar distribuída em 1.  Esses PIDs não têm nenhum significado fora do escopo de arquivo morto e, em particular, não devem ser ofuscada com os números de registro ou outros itens de identidade.  
  
 A classe de `CArchive` , os PIDs são de 32 bits, mas são gravados fora de como de 16 bits a menos que sejam maiores que 0x7FFE.  Os grandes PIDs são gravados como 0x7FFF seguido pelo PID de 32 bits.  Isso mantém a compatibilidade com projetos criados nas versões anteriores do.  
  
 Quando uma solicitação seja feita salvar um objeto a um arquivo morto \(normalmente usando o operador global de inserção\), uma verificação será feita para um ponteiro NULL de [CObject](../Topic/CObject%20Class.md) .  Se o ponteiro for NULL, `wNullTag` é inserido no fluxo de arquivo morto.  
  
 Se o ponteiro não for NULL e pode ser serializado \(a classe é uma classe de `DECLARE_SERIAL` \), as verificações de código `m_pStoreMap` para verificar se o objeto tiver sido salvo já.  Se tiver, o código insere o PID de 32 bits associado a esse objeto no fluxo de arquivo morto.  
  
 Se o objeto não foi salvo antes do, há duas possibilidades a serem consideradas: ou o objeto e o tipo exato \(isto é, a classe\) do objeto são novos neste contexto de arquivo morto, o objeto é de um tipo exato já considerados.  Para determinar se o tipo esteve considerado, o código consulta `m_pStoreMap` para um objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que corresponde ao objeto de `CRuntimeClass` associado ao objeto que está sendo salvo.  Se houver uma correspondência, `WriteObject` insere uma marca que é `OR` bit contrário de `wOldClassTag` e desse índice.  Se `CRuntimeClass` é nova neste contexto de arquivo, `WriteObject` atribui um novo PID para essa classe e inseri\-lo no arquivo, precedido pelo valor de `wNewClassTag` .  
  
 O descritor dessa classe é inserido no arquivo morto usando o método de `CRuntimeClass::Store` .  `CRuntimeClass::Store` insere o número de esquema da classe \(consulte abaixo\) e o nome de texto ASCII da classe.  Observe que o uso do nome de texto ASCII não garanta a exclusividade de arquivo morto pelos aplicativos.  Em virtude disso, você deve codificar seus arquivos de dados para evitar dano.  Após a inserção de informações da classe, o arquivo morto coloca o objeto em `m_pStoreMap` e chame o método de `Serialize` para inserir dados específicos classe.  Coloque o objeto em `m_pStoreMap` antes de chamar `Serialize` impede que as várias cópias de objeto foram salvas no repositório.  
  
 Ao retornar ao chamador inicial \(normalmente a raiz de rede de objetos\), chame [CArchive::Close](../Topic/CArchive::Close.md).  Se você pretende executar outras operações de [CFile](../mfc/reference/cfile-class.md), você deve chamar o método [Ocorrência](../Topic/CArchive::Flush.md) de `CArchive` para evitar dano de arquivo morto.  
  
> [!NOTE]
>  Essa implementação impõe um limite fixo de índices 0x3FFFFFFE pelo contexto de arquivo morto.  Esse número representará o número máximo de objetos exclusivos e de classes que podem ser salvos em um único arquivo, mas um único arquivo de disco pode ter um número ilimitado de contextos de arquivo morto.  
  
## Objetos de carga de CArchive::ReadObject \(Store\)  
 Carregar \(\) extrair objetos usa o método de `CArchive::ReadObject` e é o inverso de `WriteObject`.  Como com `WriteObject`, `ReadObject` não é chamado diretamente pelo código de usuário; o código de usuário deve chamar o operador fortemente tipado de extração que chama `ReadObject` com `CRuntimeClass`esperado.  Isso garante a integridade do tipo de operação de extração.  
  
 Desde a implementação de `WriteObject` atribuída os PIDs do crescent, começando com 1 \(0 são predefinidos como o objeto NULL\), a implementação de `ReadObject` pode usar uma matriz para manter o estado de contexto do arquivo morto.  Quando um PID será lido do repositório, se o PID é maior que o limite superior atual de `m_pLoadArray`, `ReadObject` sabe que um novo objeto \(ou a descrição de classe\) seguir.  
  
## Números de esquema  
 O número de esquema, que é atribuído à classe quando o método de `IMPLEMENT_SERIAL` da classe for encontrado, for “versão” da implementação da classe.  O esquema se refere à implementação da classe, não o número de vezes que um objeto foi feito persistente \(geralmente referenciado como a versão do objeto\).  
  
 Se você pretende manter ao longo do tempo várias implementações diferentes da mesma classe, incremente o esquema como você revisar a implementação do método de `Serialize` do objeto permite escrever o código que pode carregar os objetos armazenados usando versões anteriores de implementação.  
  
 O método de `CArchive::ReadObject` lançará [CArchiveException](../mfc/reference/carchiveexception-class.md) quando encontrar um número de esquema no repositório persistente que difere do número de esquema a descrição da classe na memória.  Não é fácil recuperar dessa exceção.  
  
 Você pode usar `VERSIONABLE_SCHEMA` \(combinado com `OR`bit a bit\) sua versão do esquema para manter essa exceção de reprodução.  Usando `VERSIONABLE_SCHEMA`, o código pode executar uma ação apropriada na função de `Serialize` verificando o valor de retorno de [CArchive::GetObjectSchema](../Topic/CArchive::GetObjectSchema.md).  
  
## Serializa chamar diretamente  
 Em muitos casos a sobrecarga de esquema geral de arquivo morto do objeto de `WriteObject` e de `ReadObject` não é necessária.  Este é exemplos comuns de serializar os dados em [CDocument](../Topic/CDocument%20Class.md).  Nesse caso, o método de `Serialize` de `CDocument` é chamado diretamente, não com os operadores de extração ou inserção.  O conteúdo do documento podem por sua vez usar o esquema mais geral de arquivo morto do objeto.  
  
 A chamada `Serialize` diretamente tem as seguintes vantagens e desvantagens:  
  
-   Nenhum byte adicional será adicionado ao arquivo morto antes ou depois que o objeto é serializado.  Isso não apenas os dados salvos menores, mas permite que você implementa as rotinas de `Serialize` que podem controlar todos os formatos de arquivo.  
  
-   O MFC é ajustada para que as implementações de `WriteObject` e de `ReadObject` e coleções não relacionadas serão vinculadas no aplicativo a menos que você precise o esquema mais geral de arquivo morto do objeto para qualquer outra finalidade.  
  
-   Seu código não precisa recuperar os números antigos do esquema.  Isso torna seu código de serialização do documento responsável para codificar números de esquema, números de versão do formato de arquivo, ou o que números de identificação você usa no início dos arquivos de dados.  
  
-   Qualquer objeto que é serializado com uma chamada à `Serialize` não deve usar `CArchive::GetObjectSchema` ou deve tratar um valor de retorno \(UINT\) \- 1 que indica que a versão foi desconhecida.  
  
 Como `Serialize` é chamado diretamente no documento, geralmente não é possível que os subelementos objetos de documento para referências de arquivo morto ao documento pai.  Esses objetos deverão receber um ponteiro para o documento contêiner explicitamente ou você deve usar a função de [CArchive::MapObject](../Topic/CArchive::MapObject.md) para mapear o ponteiro de `CDocument` a um PID antes que esses ponteiros de backup sejam arquivados.  
  
 Como observado anteriormente, você deve codificar informações de versão e class você mesmo quando você chama `Serialize` diretamente, que lhe permite alterar posteriormente o formato e ainda manter a compatibilidade com versões anteriores de arquivos mais antigos.  A função de `CArchive::SerializeClass` pode ser chamado explicitamente diretamente antes de serializar um objeto ou antes de chamar uma classe base.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)