

q_Learning defineParametrosHeuristica(Data* data){

float desc = data->md_learning.md_discountFactor / 100;
float learn = data->md_learning.md_learningRate / 100;
float exploit = data->md_learning.md_exploitation / 100;

q_Learning qt;
qt.discountFactor = desc;
qt.learningRate = learn;
qt.exploitation = exploit;

return qt;
}