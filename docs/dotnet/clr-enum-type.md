---
title: "Tipo enum CLR | Microsoft Docs"
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
  - "palavra-chave enum class [C++]"
  - "palavra-chave enum struct [C++]"
  - "escopo, de enum CLR"
ms.assetid: 4541d952-97bb-4e35-a7f8-d14f5f6a6606
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipo enum CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A declaração e o comportamento de enum foram alteradas de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 A declaração gerenciado de enum DMX é precedida pela palavra\-chave de `__value` .  A exibição aqui é distinguir o enum nativo de enum de CLR que é derivado de `System::ValueType`, ao sugerir uma funcionalidade análoga.  Por exemplo:  
  
```  
__value enum e1 { fail, pass };  
public __value enum e2 : unsigned short  {   
   not_ok = 1024,   
   maybe, ok = 2048   
};  
```  
  
 A nova sintaxe resolve o problema de distinguir o nativo e os enum de CLR sublinhando a natureza da classe dos últimos em vez de suas raiz do tipo de valor.  Como tal, a palavra\-chave de `__value` é descartado, substituído pelos pares espaçados da palavra\-chave de `enum class`.  Isso fornece uma simetria emparelhada de palavra\-chave para declarações de referência, do valor, e as classes da interface:  
  
```  
enum class ec;  
value class vc;  
ref class rc;  
interface class ic;  
```  
  
 A conversão do par `e1` e `e2` de enumeração na nova sintaxe seguinte aparência:  
  
```  
enum class e1 { fail, pass };  
public enum class e2 : unsigned short {   
   not_ok = 1024,  
   maybe, ok = 2048   
};  
```  
  
 Além dessa alteração sintática pequena, o comportamento do tipo de enum de CLR foi alterado em várias maneiras:  
  
-   Uma declaração frente de um enum de CLR não tem mais suporte.  Não há nenhum mapeamento.  É sinalizado simplesmente como um erro de tempo de compilação.  
  
```  
__value enum status; // Managed Extensions: ok  
enum class status;   // new syntax: error  
```  
  
-   A resolução de sobrecarga entre aritmética interno tipo e a hierarquia da classe de `Object` inverteu entre as duas versões de idioma\!  Como efeito colateral, os enum de CLR não são convertidos implicitamente em tipos aritméticos.  
  
-   Na nova sintaxe, uma enum de CLR mantém seu próprio escopo, que não é o caso em extensões gerenciadas.  Anteriormente, os enumeradores eram visíveis dentro do escopo de conteúdo de enum.  Agora, os enumeradores são encapsulados no escopo de enum.  
  
## Os enum de CLR é um tipo de objeto  
 Considere o seguinte fragmento de código:  
  
```  
__value enum status { fail, pass };  
  
void f( Object* ){ Console::WriteLine("f(Object)\n"); }  
void f( int ){ Console::WriteLine("f(int)\n"); }  
  
int main()  
{  
   status rslt = fail;  
  
   f( rslt ); // which f is invoked?  
}  
```  
  
 Para o programador do C\+\+ nativo, responder à pergunta natural da instância de `f()` sobrecarregado é chamada é a de `f(int)`.  Uma enum integrante de token é uma constante, e participa das promoções integrais padrão que têm precedência nesse caso.  E de fatos em extensões gerenciadas foi a última instância na qual a chamada resolve.  Isso gerou um número de surpresas – não quando as nós usamos em um estado de espírito do C\+\+ nativo – mas quando nós as precisamos de interagir com a estrutura existente de BCL \(biblioteca de classes base\), onde `Enum` é uma classe derivada indiretamente de `Object`.  Design de idioma de [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)] , a instância de `f()` invocou é a de `f(Object^)`.  
  
 A maneira como [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)] decidir impor esse é não oferecer suporte a conversões implícitas entre um tipo de enum de CLR e os tipos de aritmética.  Isso significa que toda a atribuição de um objeto de um tipo de enum de CLR em um tipo aritmético requer uma conversão explícita.  Assim, por exemplo, dada  
  
```  
void f( int );  
```  
  
 como um método sobrecarregado, não em extensões gerenciadas, a chamada  
  
```  
f( rslt ); // ok: Managed Extensions; error: new syntax  
```  
  
 é correto, e o valor contido dentro de `rslt` é convertido implicitamente em um valor inteiro.  Em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)], essa chamada não cria.  Para traduzi\-lo corretamente, devemos inserir um operador de conversão:  
  
```  
f( safe_cast<int>( rslt )); // ok: new syntax  
```  
  
## O escopo do tipo de enum de CLR  
 Uma das alterações entre as linguagens c e C\+\+ 2.0 era a adição em C\+\+ do escopo dentro da facilidade da estrutura.  Em C, uma estrutura é apenas uma agregação de dados sem suporte de uma interface ou de um escopo associado.  Essa era suficiente uma alteração radical momento e fosse um problema controverso para muitos novos usuários C\+\+ que vêm de C \- idioma.  A relação entre o modo nativo e o enum de CLR é análoga.  
  
 Em extensões gerenciadas, foi feita uma tentativa de definir os nomes de injetados para os enumeradores de uma enum de CLR para simular a ausência de escopo dentro do enum nativo.  Isso não provou com êxito.  O problema é que isso faz com que os enumeradores ao derramamento no namespace global, resultando em difícil gerenciar \- colisões.  Na nova sintaxe, é conformamo\-nos para os outros idiomas de CLR para suportar escopos no enum de CLR.  
  
 Isso significa que nenhum uso não qualificado de um enumerador de uma enum de CLR não será reconhecido pela nova sintaxe.  Vamos analisar um exemplo do mundo real.  
  
```  
// Managed Extensions supporting weak injection  
__gc class XDCMake {  
public:  
   __value enum _recognizerEnum {   
      UNDEFINED,  
      OPTION_USAGE,   
      XDC0001_ERR_PATH_DOES_NOT_EXIST = 1,  
      XDC0002_ERR_CANNOT_WRITE_TO = 2,  
      XDC0003_ERR_INCLUDE_TAGS_NOT_SUPPORTED = 3,  
      XDC0004_WRN_XML_LOAD_FAILURE = 4,  
      XDC0006_WRN_NONEXISTENT_FILES = 6,  
   };  
  
   ListDictionary* optionList;  
   ListDictionary* itagList;  
  
   XDCMake() {  
      optionList = new ListDictionary;  
  
      // here are the problems …  
      optionList->Add(S"?", __box(OPTION_USAGE)); // (1)  
      optionList->Add(S"help", __box(OPTION_USAGE)); // (2)  
  
      itagList = new ListDictionary;  
      itagList->Add(S"returns",   
         __box(XDC0004_WRN_XML_LOAD_FAILURE)); // (3)  
   }  
};  
```  
  
 Cada um dos três usa não qualificado de nomes de enumerador \(`(1)`, `(2)`, e `(3)`\) deverá ser qualificado a tradução para a nova sintaxe para que o código\-fonte cria.  Eis uma tradução correta do código\-fonte original:  
  
```  
ref class XDCMake {  
public:  
   enum class _recognizerEnum {  
      UNDEFINED, OPTION_USAGE,   
      XDC0001_ERR_PATH_DOES_NOT_EXIST = 1,  
      XDC0002_ERR_CANNOT_WRITE_TO = 2,  
      XDC0003_ERR_INCLUDE_TAGS_NOT_SUPPORTED = 3,  
      XDC0004_WRN_XML_LOAD_FAILURE = 4,  
      XDC0006_WRN_NONEXISTENT_FILES = 6  
   };  
  
   ListDictionary^ optionList;  
   ListDictionary^ itagList;  
  
   XDCMake() {  
      optionList = gcnew ListDictionary;  
      optionList->Add("?",_recognizerEnum::OPTION_USAGE); // (1)  
      optionList->Add("help",_recognizerEnum::OPTION_USAGE); //(2)  
      itagList = gcnew ListDictionary;  
      itagList->Add( "returns",   
         _recognizerEnum::XDC0004_WRN_XML_LOAD_FAILURE); //(3)  
   }  
};  
```  
  
 Isso altera a estratégia de design entre um nativo e uma enum de CLR.  Com uma enum de CLR que mantém um escopo associado em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)], não é necessário ou efetiva para encapsular a declaração de enum em uma classe.  Esse idioma evoluiu em torno de 2,0 horas cfront nos laboratórios de Sino também para resolver o problema global da poluição do nome.  
  
 Na versão beta original da nova biblioteca iostream por Jerry Schwarz nos laboratórios de Sino, Jerry não encapsulou todos os enum associado definida para a biblioteca, e os enumeradores comuns como `read`, `write`, `append`, e assim por diante, que fizeram praticamente impossível para que os usuários compilar o código existente.  Uma solução seria massacrar os nomes, como `io_read`, `io_write`, etc. Uma segunda solução seria alterar o idioma adicionando o escopo de uma enum, mas não era possível naquele momento.  A solução intermediária foi encapsular o enum na classe, ou da hierarquia da classe, onde o nome da marca e os enumeradores de enum populam o escopo incluindo da classe.\) Isto é, a motivação para colocar enum dentro das classes, pelo menos, era originalmente não filosófica, mas uma resposta prática para o problema global da poluição de \- espaço.  
  
 Com o enum de [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)] , não há mais qualquer benefício de deve a encapsular uma enum em uma classe.  De fato, se você examina os namespaces de `System` , verá que os enum, as classes e interfaces, todos habitam o mesmo espaço da declaração.  
  
## Consulte também  
 [Tipos de valor e seus comportamentos \(C\+\+\/CLI\)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [enum class](../windows/enum-class-cpp-component-extensions.md)